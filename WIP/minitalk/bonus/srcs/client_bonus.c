/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:30:27 by echung            #+#    #+#             */
/*   Updated: 2021/10/06 19:27:12 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send(int pid, unsigned char c)
{
	int	digit;
	//int	count_send;

	digit = 1 << 7;
	//count_send = 0;
	while (digit > 0)
	{
		if ((digit & c) && kill(pid, SIGUSR1) != -1)
		{
			digit >>= 1;
			//count_send++;
		}
		else if (kill(pid, SIGUSR2) != -1)
		{
			digit >>= 1;
			//count_send++;
		}
		else
			return ;
		usleep(100);
	}
}

static void	preprocess(char *pid, char *message)
{
	int	send_pid;

	send_pid = ft_atoi(pid);
	while (*message != '\0')
	{
		send(send_pid, *message);
		message++;
	}
}

static int	is_valid_pid(char *pid)
{
	if ((ft_isinteger(pid)) && (ft_strlen(pid) <= 5))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	if ((argc == 3) && (is_valid_pid(argv[1])))
		preprocess(argv[1], argv[2]);
	else
		ft_putstr_fd("Input error.\n", 2);
	return (0);
}
