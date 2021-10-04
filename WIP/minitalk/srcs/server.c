/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:51:39 by echung            #+#    #+#             */
/*   Updated: 2021/10/04 20:14:13 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_handler(int signum)
{
	static int	binary = 0;
	static int	i = 0;
	char		result;

	if (signum == SIGUSR1)
	{
		binary = binary << 1;
		binary += 1;
		i++;
	}
	else if (signum == SIGUSR2)
	{
		binary = binary << 1;
		i++;
	}
	else
		return ;
	if (i != 0 && i % 8 == 0)
	{
		result = (char)binary;
		ft_putchar_fd(result, 1);
	}
}

int	main(void)
{
	if (signal(SIGUSR1, my_handler) == SIG_ERR
		|| signal(SIGUSR2, my_handler) == SIG_ERR)
	{
		ft_putstr_fd("Sig error.\n", 2);
		return (0);
	}
	ft_putstr_fd("server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
