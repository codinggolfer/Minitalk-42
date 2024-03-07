/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:06:58 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:37:55 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t z)
{
	unsigned char	*dest;
	int				i;

	dest = str;
	i = 0;
	while (z > 0)
	{
		dest[i] = '\0';
		i++;
		z--;
	}
}
