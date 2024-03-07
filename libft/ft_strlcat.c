/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:32:34 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:33 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	slen = 0;
	while (dlen < dstsize && dst[dlen] != '\0')
	{
		dlen++;
	}
	while ((dlen + slen + 1) < dstsize && src[slen] != '\0')
	{
		dst[dlen + slen] = src[slen];
		slen++;
	}
	if (dlen != dstsize)
		dst[dlen + slen] = '\0';
	return (dlen + ft_strlen(src));
}
