/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:56:51 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/12 17:42:10 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_signal	g_signals;

static void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;
	int		s1;
	int		s2;
	char	c;

	tmp = n;
	s1 = tmp / 10;
	s2 = tmp % 10;
	if (s1 != 0)
		ft_putnbr_fd(s1, fd);
	c = s2 + '0';
	write(fd, &c, 1);
}

static void	ft_receive_message(int signal)
{
	if (signal == SIGUSR1)
	{
		if (g_signals.count == 0)
			g_signals.ascii += 1;
		else
			g_signals.ascii += g_signals.digit;
	}
	if (g_signals.count == 0)
	{
		write(1, &(g_signals.ascii), 1);
		g_signals.count = 7;
		g_signals.ascii = 0;
		g_signals.digit = 128;
		return ;
	}
	g_signals.count--;
	g_signals.digit /= 2;
}

int	main(void)
{
	g_signals.count = 7;
	g_signals.ascii = 0;
	g_signals.digit = 128;
	write(1, "server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	if (signal(SIGUSR1, &ft_receive_message) != 0)
		return (ERROR);
	if (signal(SIGUSR2, &ft_receive_message) != 0)
		return (ERROR);
	while (1)
		pause();
}
