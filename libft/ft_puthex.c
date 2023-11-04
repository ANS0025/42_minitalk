/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:56:36 by akiseki           #+#    #+#             */
/*   Updated: 2023/09/18 15:57:07 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16);
	if (n % 16 < 10)
		count += ft_putchar(n % 16 + '0');
	else
		count += ft_putchar(n % 16 - 10 + 'a');
	return (count);
}
