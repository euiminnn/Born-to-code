/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:55:42 by echung            #+#    #+#             */
/*   Updated: 2021/07/13 22:58:48 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num)
{
	ft_putchar_fd(num, 1);
}

int		main(void)
{
	if ((signal(SIGUSR1, handler) == SIG_ERR)
			|| (signal(SIGUSR2, handler) == SIG_ERR))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	
	printf("PID: %d\n", getpid());
}
