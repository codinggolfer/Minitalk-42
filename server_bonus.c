/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:27:14 by eagbomei          #+#    #+#             */
/*   Updated: 2024/03/07 17:13:34 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	ft_serverb_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	shift = 0;

	(void)context;
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
	if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	else if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to the server\n");
	ft_printf("Your PID is here %i:\n", getpid());
	sa.sa_sigaction = handler;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_serverb_error("sigaction failure");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_serverb_error("sigaction failure");
		pause();
	}
}
