/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:53:21 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/12 12:45:15 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrd_count(const char *s, char c)
{
	size_t	words;

	if (s == 0)
		return (0);
	words = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (words);
}

static char	**free_all(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != '\0')
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		end;
	size_t		start;
	size_t		i;

	start = 0;
	i = 0;
	split = (char **) ft_calloc (ft_wrd_count(s, c) + 1, sizeof(char *));
	if (split == 0)
		return (0);
	while (s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] == 0)
			return (split);
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		split[i] = ft_substr(s, start, end - start);
		if (split[i++] == '\0')
			return (free_all(split));
		start = end;
	}
	return (split);
}
