/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:30:27 by echung            #+#    #+#             */
/*   Updated: 2021/07/19 01:50:52 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, unsigned char c)
{
	int cal;

	cal = 1 << 7;		//1000 0000(2)
	if (c)
	{
		while (cal)
		{
			if ((cal & c) && kill(pid, SIGUSR1) > 0)	//SIGUSR1 = 1;
				cal = cal >> 1;
			else if (kill(pid, SIGUSR2) > 0)			//SIGUSR2 = 0;
				cal = cal >> 1;
			else
				return (0);
		}
	}
}

void	preprocess(char *pid, char *message)
{
	int	pid;
	
	pid = ft_atoi(pid);
	while (*message != '\0')
	{
		send(pid, *message);
		message++;
	}
}

int	is_valid_arg(char **argv)
{
	if ((argv[0] == './client')
		&& (argv[1] > 0 && argv[1] < 99999)
		&& (argv[2] == str))
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
