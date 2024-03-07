/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:36:07 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/02 15:00:43 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(uintptr_t len)
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

static int	hex_address(uintptr_t i)
{
	if (i >= 16)
	{
		if (hex_address(i / 16) < 0)
			return (-1);
		i = i % 16;
	}
	if (i <= 9)
	{
		if (print_char(i + 48) < 0)
			return (-1);
	}
	else
		if (print_char(i - 10 + 'a') < 0)
			return (-1);
	return (0);
}

int	address_printer(uintptr_t i)
{
	int	print_lenght;

	print_lenght = 0;
	print_lenght += print_str("0x");
	if (print_lenght < 0)
		return (-1);
	if (i <= 9)
	{
		if (print_char(i + 48) < 0)
			return (-1);
		return (1 + print_lenght);
	}
	else
		if (hex_address(i) < 0)
			return (-1);
	return (ft_int_len(i) + print_lenght);
}
