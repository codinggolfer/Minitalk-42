/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:31 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 14:33:06 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t len)
{
	unsigned char		*dest;
	unsigned const char	*src;

	dest = to;
	src = from;
	if (dest > src)
	{
		while (len > 0)
		{
			dest[len - 1] = src[len - 1];
			len--;
		}
	}
	else if (dest < src)
	{
		while (len > 0)
		{
			*dest = *src;
			dest++;
			src++;
			len--;
		}
	}
	return (to);
}
