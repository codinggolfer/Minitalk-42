/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:59:28 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/02 15:00:16 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(unsigned int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (1);
	while (len / 16)
	{
		i++;
		len = len / 16;
	}
	i++;
	return (i);
}

static int	hex_address(const char format, unsigned int i)
{
	if (i >= 16)
	{
		if (hex_address(format, i / 16) < 0)
			return (-1);
		i = i % 16;
	}
	if (i <= 9)
	{
		if (print_char(i + 48) < 0)
			return (-1);
	}
	else
	{
		if (format == 'x')
			if (print_char(i - 10 + 'a') < 0)
				return (-1);
		if (format == 'X')
			if (print_char(i - 10 + 'A') < 0)
				return (-1);
	}
	return (0);
}

int	hex_printer(const char format, unsigned int i)
{
	if (i <= 9)
	{
		if (print_char(i + 48) < 0)
			return (-1);
		return (1);
	}
	else
		if (hex_address(format, i) < 0)
			return (-1);
	return (ft_int_len(i));
}
