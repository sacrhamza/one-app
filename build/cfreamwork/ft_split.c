/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:14:42 by hsacr             #+#    #+#             */
/*   Updated: 2025/03/28 23:00:20 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_word_length(char const *s, char c, int index);

static char	*ft_split_store(char const *s, char *ptr, char c, int index)
{
	size_t	i;
	int		index_expected;
	size_t	j;

	j = 0;
	i = 0;
	index_expected = 0;
	while (*(s + i) != 0)
	{
		while (*(s + i) == c && *(s + i) != 0)
			i++;
		if (index_expected == index && *(s + i) != c && *(s + i) != 0)
		{
			j = 0;
			while (j < ft_split_word_length(s, c, index))
				*(ptr + j++) = *(s + i++);
			*(ptr + j) = 0;
		}
		while (*(s + i) != c && *(s + i) != 0)
			i++;
		index_expected++;
	}
	return (0);
}

static size_t	ft_split_word_length(char const *s, char c, int index)
{
	size_t	length;
	int		index_expected;
	size_t	i;

	i = 0;
	index_expected = 0;
	length = 0;
	while (*(s + i) != 0)
	{
		length = 0;
		while (*(s + i) == c && *(s + i) != 0)
			i++;
		while (*(s + i) != c && *(s + i) != 0)
		{
			length++;
			i++;
		}
		if (index_expected == index)
			return (length);
		index_expected++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	ptr = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (ptr == 0)
		return (0);
	while (i < ft_word_count(s, c))
	{
		*(ptr + i) = (char *)malloc((ft_split_word_length(s, c, i) + 1)
				*sizeof(char));
		if (*(ptr + i) == 0)
		{
			while (i != 0)
				free(*(ptr + --i));
			free(ptr);
			return (0);
		}
		ft_split_store(s, *(ptr + i), c, i);
		i++;
	}
	*(ptr + i) = 0;
	return (ptr);
}
