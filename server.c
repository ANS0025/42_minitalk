/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:52:00 by akiseki           #+#    #+#             */
/*   Updated: 2023/11/05 17:52:05 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	byte;

	(void)context;
	if (sig == SIGUSR1)
		byte += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write (1, &byte, 1);
		if (byte == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
		byte = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("No arguments needed!\n");
		return (1);
	}
	ft_printf("PID: ");
	pid = getpid();
	ft_printf("%d\n", pid);
	action.sa_sigaction = bin_to_char;
	action.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
