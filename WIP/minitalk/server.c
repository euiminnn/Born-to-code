/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:55:42 by echung            #+#    #+#             */
/*   Updated: 2021/07/10 19:18:25 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num)
{
	ft_putchar_fd(num, 1);
}
int		main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("PID: %d\n", getpid());
}
