/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <akiseki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:44:35 by akiseki           #+#    #+#             */
/*   Updated: 2023/02/26 01:44:38 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c || *s == '\0')
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*copy_word(char const *s, char c)
{
	unsigned long	len;
	char			*new_word;

	len = 0;
	while (s[len] && s[len] != c && s[len] != '\0')
		len++;
	new_word = (char *)malloc(len + 1);
	if (new_word == NULL)
		return (NULL);
	ft_memcpy(new_word, s, len);
	new_word[len] = '\0';
	return (new_word);
}

static void	ft_allocate(char **result, char const *s, char c)
{
	char	**rp;

	rp = result;
	while (*s)
	{
		if (*s == c || *s == '\0')
			s++;
		else
		{
			*rp = copy_word(s, c);
			if (*rp == NULL)
			{
				while (result != rp)
					free(*--rp);
				free(result);
				*result = NULL;
				return ;
			}
			rp++;
			while (*s && *s != c && *s != '\0')
				s++;
		}
	}
	*rp = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	ft_allocate(result, s, c);
	return (result);
}
