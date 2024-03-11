/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:27:04 by eagbomei          #+#    #+#             */
/*   Updated: 2024/03/11 14:36:54 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	ft_clientb_error(char *msg)
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
				ft_clientb_error("kill function failure");
		}
		else
			if (kill(pid, SIGUSR1) == -1)
				ft_clientb_error("kill function failure");
		usleep(100);
		shift++;
	}
}

void	client_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("server recieved message succesfully\n", 1);
}

int	main(int ac, char **av)
{
	int					pid;
	char				*str;
	int					i;
	struct sigaction	sa;

	i = 0;
	sa.sa_handler = client_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_clientb_error("sigaction failure");
	if (ac == 3)
	{
		while (av[1][i] != '\0')
			if (!ft_isdigit(av[1][i++]))
				ft_clientb_error("invalid pid");
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
			send_bit(pid, *str++);
		send_bit(pid, '\0');
	}
	else
		ft_clientb_error("Too few arguments or too many arguments");
	return (0);
}
