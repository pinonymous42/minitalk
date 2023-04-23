/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:29:11 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/12 14:23:49 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define ERROR 1
# define FINISH 0
# define EOT 4

typedef struct s_signal
{
	int	count;
	int	ascii;
	int	digit;
}t_signal;

#endif