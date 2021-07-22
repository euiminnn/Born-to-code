/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:30:27 by echung            #+#    #+#             */
/*   Updated: 2021/07/22 21:05:43 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, unsigned char c)
{
	int	cal;
	int	count_send;

	cal = 1 << 7; // 1000 0000(2)
	count_send = 0;
	while (cal > 0)
	{
		if ((cal & c) && kill(pid, SIGUSR1) != -1) // SIGUSR1 = 1;
		{
			cal = cal >> 1;
			count_send++;
		}
		else if (kill(pid, SIGUSR2) != -1) // SIGUSR2 = 0;
		{
			cal = cal >> 1;
			count_send++;
		}
		else
			return ;
		usleep(100);
	}
}

void	preprocess(char *pid, char *message)
{
	int	send_pid;

	send_pid = ft_atoi(pid);
	while (*message != '\0')
	{
		send(send_pid, *message);
		message++;
	}
}

int	ft_isinteger(char *c)
{
	if (*c == '\0')
		return (0);
	while (*c != '\0')
	{
		if ('0' <= *c && *c <= '9')
			c++;
		else
			return (0);
	}
	return (1);
}

int	is_valid_arg(char **argv)
{
	if ((ft_isinteger(argv[1])) && (ft_strlen(argv[1]) <= 5))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	if ((argc == 3) && (is_valid_arg(argv)))
		preprocess(argv[1], argv[2]);
	else
		ft_putstr_fd("Input error.\n", 2);
	return (0);
}
