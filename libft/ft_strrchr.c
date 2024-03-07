/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:36:35 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:44 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	a;
	size_t			len;

	a = c;
	len = ft_strlen(str) + 1;
	while (*str != '\0')
		str++;
	while (len--)
	{
		if (*str == a)
			return ((char *)str);
		str--;
	}
	return (0);
}
