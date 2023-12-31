/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:52:20 by akiseki           #+#    #+#             */
/*   Updated: 2023/11/05 17:52:22 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_check(int sig)
{
	(void)sig;
	write(1, "Server has received the message\n", 33);
}

void	char_to_bin(pid_t pid, char c)
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

	if (argc != 3)
	{
		ft_printf("ERROR: Incorrect number of arguments\n");
		return (1);
	}
	pid = atoi(argv[1]);
	if (pid <= 0 || pid > INT_MAX)
	{
		ft_printf("ERROR: Invalid PID\n");
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(pid, argv[2][i]);
		i++;
	}
	signal(SIGUSR2, server_check);
	char_to_bin(pid, '\n');
	char_to_bin(pid, '\0');
	return (0);
}
