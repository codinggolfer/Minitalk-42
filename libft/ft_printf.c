/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:01:14 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/02 15:00:25 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

static int	check_format(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += print_char(va_arg(ap, int));
	else if (format == 's')
		print_len += print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len += address_printer(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_number(va_arg(ap, int));
	else if (format == 'u')
		print_len += print_unint(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += hex_printer(format, va_arg(ap, unsigned int));
	else if (format == '%')
		print_len += print_char('%');
	return (print_len);
}

static int	browse_strings(va_list ap, const char *str, int result)
{
	int	i;
	int	print_length;

	i = 0;
	print_length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result = check_format(ap, str[i + 1]);
			if (result == -1)
				return (-1);
			i++;
			print_length += result;
		}
		else
		{
			result = print_char(str[i]);
			if (result == -1)
				return (-1);
			print_length += result;
		}
		i++;
	}
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		print_length;
	va_list	ap;
	int		result;

	print_length = 0;
	result = 0;
	va_start(ap, str);
	print_length += browse_strings(ap, str, result);
	va_end(ap);
	return (print_length);
}
