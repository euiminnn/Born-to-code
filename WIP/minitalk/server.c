/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:51:39 by echung            #+#    #+#             */
/*   Updated: 2021/07/20 23:39:21 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int signum)
{
	int binary;
	int i;
	int result;
	
	binary = 0;
	i = 0;
	while (i < 8)
	{
		if (signum == SIGUSR1)
		{
			binary = binary << 1;
			binary += 1;
		}
		else if (signum == SIGUSR2)
		{
			binary = binary << 1;
		}
		else
			return ;
		i++;
	}
	result = binary + '0' - '0';
	ft_putchar_fd(result, 1);
}

int	main(void)
{
	if (signal(SIGUSR1, my_handler) == SIG_ERR ||
			signal(SIGUSR2, my_handler) == SIG_ERR)
	{
		ft_putstr_fd("Sig error.\n", 2);
		return (0);
	}
	ft_putstr_fd("server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
