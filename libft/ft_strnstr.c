/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:55:18 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:27:43 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		ln;

	i = 0;
	j = 0;
	ln = len;
	if (needle[0] == 0)
		return ((char *) haystack);
	if (haystack == 0 && len == 0)
		return (0);
	while (haystack[i] != '\0' && len--)
	{
		while (haystack[i + j] == needle[j] && ln > 0)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
			ln--;
		}
		j = 0;
		ln = len;
		i++;
	}
	return (0);
}
