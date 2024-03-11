/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:28:17 by eagbomei          #+#    #+#             */
/*   Updated: 2024/03/11 13:41:21 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_client_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (1);
}

void	send_bit(int pid, char c)
{
	int		shift;

	shift = 0;
	while (shift < 7)
	{
		if ((c >> shift) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_client_error("kill function failure");
		}
		else
			if (kill(pid, SIGUSR1) == -1)
				ft_client_error("kill function failure");
		usleep(100);
		shift++;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	char				*str;
	int					i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
			if (!ft_isdigit(av[1][i++]))
				ft_client_error("invalid pid");
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
			send_bit(pid, *str++);
		send_bit(pid, '\0');
	}
	else
		ft_client_error("Too few arguments or too many arguments");
	return (0);
}
