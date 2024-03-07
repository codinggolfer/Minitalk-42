/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:45:53 by eagbomei          #+#    #+#             */
/*   Updated: 2024/03/07 16:08:39 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_server_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (1);
}

void	handler(int signum)
{
	static int	c = 0;
	static int	shift = 0;

	if (signum == SIGUSR2)
		c += 1 << shift;
	else if (signum == SIGUSR1)
		c += 0 << shift;
	shift++;
	if (shift == 7)
	{
		ft_putchar_fd(c, 1);
		shift = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to the server\n");
	ft_printf("Your PID is here %i:\n", getpid());
	sa.sa_handler = handler;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_server_error("sigaction failure");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_server_error("sigaction failure");
		pause();
	}
}
