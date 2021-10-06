/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:51:39 by echung            #+#    #+#             */
/*   Updated: 2021/10/06 20:23:49 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_handler(int signum)
{
	static int	binary = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
	{
		binary <<= 1;
		binary += 1;
		i++;
	}
	else if (signum == SIGUSR2)
	{
		binary <<= 1;
		i++;
	}
	if (i == 8)
	{
		ft_putchar_fd(binary, 1);
		binary = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (signal(SIGUSR1, my_handler) == SIG_ERR
		|| signal(SIGUSR2, my_handler) == SIG_ERR)
	{
		ft_putstr_fd("Sig error.\n", 2);
		return (0);
	}
	while (1)
		pause();
	return (0);
}
