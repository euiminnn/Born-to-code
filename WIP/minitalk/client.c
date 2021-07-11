/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:55:53 by echung            #+#    #+#             */
/*   Updated: 2021/07/11 17:16:35 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(int pid, char *str)
{
	int i;

	while (*str != '\0')
	{
		i = 0;
		while (i < 8)
		{
			if ()
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i++;
		}
		str++;
	}
}

int 	main(int argc, char **argv)
{
	client(pid, argv[2]);
	return (0);
}
