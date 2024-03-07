/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:07:52 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/02 15:01:34 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(unsigned int len)
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

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	c_value;

	len = ft_int_len(n);
	str = ((char *) malloc (ft_int_len(n) + 1 * sizeof(char)));
	if (str == 0)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		c_value = n % 10 + '0';
		n = n / 10;
		str[len] = c_value;
	}
	return (str);
}

int	print_unint(unsigned int i)
{
	char	*number;

	number = ft_uitoa(i);
	if (number == 0)
	{
		free (number);
		return (-1);
	}
	if (print_str(number) < 0)
	{
		free(number);
		return (-1);
	}
	free (number);
	return (ft_int_len(i));
}
