#include "minitalk.h"

void	server_check(int sig)
{
	(void)sig;
	write(1, "Received the message\n", 22);
}

void	ctos(pid_t pid, char c)
{
	static int	bit;

	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
	bit = 0;
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			ctos(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, server_check);
		ctos(pid, '\n');
		ctos(pid, '\0');
	}
	else
	{
		ft_printf("ERROR, Arguments passed	problem\n");
		return (1);
	}
	return (0);
}