#include "minitalk.h"

void bin_to_char(int signum, char* c)
{
    static int i = 0;
    if (signum == SIGUSR1)
        *c = (*c << 1) | 1;
    else if (signum == SIGUSR2)
        *c <<= 1;
    if (++i == 8)
    {
        i = 0;
        if (!*c)
        {
            kill(getpid(), SIGUSR1);
            *c = '\0';
        }
        printf("%c", *c);
        *c = '\0';
    }
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
    static int pid = 0;
    static int i = 0;
    static char c = '\0';
    (void)context;
    pid = info->si_pid;
    bin_to_char(signum, &c);
    if (++i == 32)
    {
        i = 0;
        kill(pid, SIGUSR1);
    }
    else
        kill(pid, SIGUSR2);
}

int main(void)
{
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    printf("Server PID: %d\n", getpid());
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        printf("Error setting up signal handlers\n");
        return (1);
    }
    while (1)
        pause();
    return (0);
}