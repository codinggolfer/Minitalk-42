/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:56:48 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:31:26 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		a;
	size_t				len;

	a = c;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s++;
	}
	return (0);
}
