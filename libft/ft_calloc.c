/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:36:19 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/15 12:51:59 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t blocks, size_t bsize)
{
	void	*ptr;
	size_t	max;

	max = 0 - 1;
	if (blocks != 0)
		if (max / blocks < bsize)
			return (0);
	if ((blocks * bsize) > 2147483423)
		return (0);
	ptr = malloc(blocks * bsize);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, blocks * bsize);
	return (ptr);
}
