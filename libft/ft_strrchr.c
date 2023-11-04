/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:54:02 by akiseki           #+#    #+#             */
/*   Updated: 2023/02/26 01:54:02 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = 0;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
		{
			last = (char *)str;
		}
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (last);
}
