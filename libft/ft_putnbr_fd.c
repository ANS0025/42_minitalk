/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:48:11 by akiseki           #+#    #+#             */
/*   Updated: 2023/02/26 01:48:13 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		flag;
	char	c;

	flag = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		flag = -1;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * flag, fd);
	c = n % 10 * flag + '0';
	write(fd, &c, 1);
}
