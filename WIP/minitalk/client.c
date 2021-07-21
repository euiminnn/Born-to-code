/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:30:27 by echung            #+#    #+#             */
/*   Updated: 2021/07/21 10:04:41 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send(int pid, unsigned char c)
{
	int cal;
	int count_send = 0;

	cal = 1 << 7;		//1000 0000(2)
	//printf("cal = %d\n", cal);
	while (cal > 0)
	{
		printf("char = %c\n", c);
		if (cal & c)
			printf("yes\n");
		if ((cal & c) && kill(pid, SIGUSR1) != -1)	//SIGUSR1 = 1;
		{
			printf("cal sigusr1 = %d\n", cal);
			cal = cal >> 1;
			count_send++;

		}
		else if (kill(pid, SIGUSR2) != -1)			//SIGUSR2 = 0;
		{
			printf("cal sigusr2 = %d\n", cal);
			cal = cal >> 1;
			count_send++;
		}
		else
			return ;
		printf("send count: %d\n", count_send);
		usleep(100);
	}
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
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
	printf("message = %s\n", argv[2]);
	return (0);
}
