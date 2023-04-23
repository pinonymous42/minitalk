/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:56:49 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/12 17:40:36 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static int	ft_atoi(const char *str)
{
	long	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i);
}

static void	ft_send_character(int pid, int character)
{
	int	i;
	int	conseq;

	i = 7;
	while (i >= 0)
	{
		if (((character >> i) & 1) == 1)
			conseq = kill(pid, SIGUSR1);
		else
			conseq = kill(pid, SIGUSR2);
		if (conseq == -1)
			exit(ERROR);
		i--;
		usleep(60);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || argv[1][0] == '-')
		return (ERROR);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || 99998 < pid)
		return (ERROR);
	while (*argv[2])
	{
		ft_send_character(pid, *argv[2]);
		argv[2]++;
	}
	ft_send_character(pid, EOT);
	return (FINISH);
}
