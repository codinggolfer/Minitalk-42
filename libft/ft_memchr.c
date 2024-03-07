/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:19:07 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:34:19 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char				a;
	unsigned const char			*str;

	a = c;
	str = s;
	while (n > 0)
	{
		if (*str == a)
			return ((unsigned char *) str);
		str++;
		n--;
	}
	return (0);
}
