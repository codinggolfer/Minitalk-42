/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:45:53 by eagbomei          #+#    #+#             */
/*   Updated: 2024/03/11 13:33:41 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static char	*append_string(char *lines, char ret)
{
	char		*temp;
	static char	tstr[2];

	tstr[0] = ret;
	tstr[1] = '\0';
	temp = ft_strjoin(lines, tstr);
	free(lines);
	return (temp);
}

void	ft_server_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (1);
}

void	handler(int signum)
{
	static int	c = 0;
	static int	shift = 0;
	static char	*str = NULL;

	if (signum == SIGUSR2)
		c += 1 << shift;
	else if (signum == SIGUSR1)
		c += 0 << shift;
	shift++;
	if (shift == 7)
	{
		if (!str)
			str = ft_strdup("");
		str = append_string(str, c);
		shift = 0;
		if (c == 0)
		{
			ft_printf("%s\n", str, 1);
			free(str);
			str = NULL;
		}
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to the server\n");
	ft_printf("Your PID is here %i:\n", getpid());
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_server_error("sigaction failure");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_server_error("sigaction failure");
		pause();
	}
}
