/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:45:28 by akiseki           #+#    #+#             */
/*   Updated: 2023/02/26 01:45:29 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while (i < n)
	{
		u1 = (unsigned char)s1[i];
		u2 = (unsigned char)s2[i];
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0' || u2 == '\0')
			break ;
		i++;
	}
	if (i == n)
		return (0);
	u1 = (unsigned char)s1[i];
	u2 = (unsigned char)s2[i];
	return (u1 - u2);
}
