/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:51:39 by echung            #+#    #+#             */
/*   Updated: 2021/10/06 19:27:09 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int binary = 0;
int i = 0;

static void	handler_one(int signum)
{
	if (signum == SIGUSR1)
	{
		binary <<= 1;
		binary += 1;
		i++;
	}
	else
		return ;
}

static void	handler_two(int signum)
{
	if (signum == SIGUSR2)
	{
		binary <<= 1;
		i++;
	}
	else
		return ;
}

int	main(void)
{
	ft_putstr_fd("server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (signal(SIGUSR1, handler_one) == SIG_ERR
		|| signal(SIGUSR2, handler_two) == SIG_ERR)
	{
		ft_putstr_fd("Sig error.\n", 2);
		return (0);
	}
	char		result;

	if (i != 0 && i % 8 == 0)
	{
		result = (char)binary;
		ft_putchar_fd(result, 1);
	}
	while (1)
		pause();


	return (0);
}
