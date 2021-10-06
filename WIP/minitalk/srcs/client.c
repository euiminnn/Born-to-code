/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:30:27 by echung            #+#    #+#             */
/*   Updated: 2021/10/06 20:23:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send(int pid, unsigned char c)
{
	int	digit;

	digit = 1 << 7;
	while (digit > 0)
	{
		if (digit & c)
		{
			kill(pid, SIGUSR1);
			digit >>= 1;
		}
		else
		{
			kill(pid, SIGUSR2);
			digit >>= 1;
		}
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
