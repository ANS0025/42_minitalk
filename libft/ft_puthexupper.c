/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:55:34 by akiseki           #+#    #+#             */
/*   Updated: 2023/09/18 15:55:36 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexupper(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexupper(n / 16);
	if (n % 16 < 10)
		count += ft_putchar(n % 16 + '0');
	else
		count += ft_putchar(n % 16 - 10 + 'A');
	return (count);
}
