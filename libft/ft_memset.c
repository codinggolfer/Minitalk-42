/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:15 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:32:24 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	z;
	int				i;
	char			*dest;

	i = 0;
	z = c;
	dest = b;
	while (len > 0)
	{
		dest[i] = z;
		i++;
		len--;
	}
	return (b);
}
