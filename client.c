#include "minitalk.h"

static volatile	sig_atomic_t	g_receiver = 0;

void	sig_handler(int signum, siginfo_t* info, void* context)
{
	static int i = 0;
	(void)info;
	(void)context;
	g_receiver = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
	{
		printf("Received %d bytes\n", i / 8);
		i = 0;
	}
}

int char_to_bin(char c, int pid)
{
    int itr = 0;
    int bit_index = 7;
    while (bit_index >= 0)
    {
        itr = 0;
        if ((c >> bit_index) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (g_receiver == 0)
        {
            if (itr == 50)
            {
                printf("No response from server\n");
                exit(EXIT_FAILURE);
            }
            itr++;
            usleep(100);
        }
        g_receiver = 0;
        bit_index--;
    }
    return (0);
}

int main(int argc, char* argv[])
{
    struct sigaction sa;
    int byte_index = 0;
    int pid;

    if (argc != 3)
    {
        printf("Usage: %s [server PID] [message]\n", argv[0]);
        return (1);
    }
    pid = atoi(argv[1]);
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        printf("Error setting up signal handlers\n");
        return (1);
    }
    while (argv[2][byte_index])
    {
        char_to_bin(argv[2][byte_index], pid);
        byte_index++;
    }
    char_to_bin('\0', pid);
    return (0);
}