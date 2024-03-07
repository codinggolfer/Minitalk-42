/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:20:48 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/13 13:34:46 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (1);
	while (len / 10)
	{
		i++;
		len = len / 10;
	}
	i++;
	return (i);
}

static char	*ft_i_to_a(char *str, long n, int minus, int len)
{
	size_t	c_value;

	str[len + minus] = '\0';
	while (len + minus > 0)
	{
		len--;
		c_value = n % 10 + '0';
		n = n / 10;
		str[len + minus] = c_value;
	}
	if (minus > 0)
		str[len + minus] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			minus;
	long		nb;

	nb = n;
	len = ft_int_len(n);
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		nb *= -1;
	}
	str = ((char *) malloc (ft_int_len(n) + minus + 1 * sizeof(char)));
	if (str == 0)
		return (0);
	ft_i_to_a(str, nb, minus, len);
	return (str);
}
