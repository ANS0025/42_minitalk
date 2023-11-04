/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:49:20 by akiseki           #+#    #+#             */
/*   Updated: 2023/02/26 01:50:36 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!haystack && len == 0)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	if (!ft_strlen(haystack) || ft_strlen(needle) > len)
		return (NULL);
	while (len-- >= ft_strlen(needle))
	{
		if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
