/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:59:36 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:42:33 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	int			i;
	char		*dest;
	const char	*src;

	i = 0;
	dest = to;
	src = from;
	if (dest == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (to);
}
