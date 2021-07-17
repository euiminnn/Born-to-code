/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:55:53 by echung            #+#    #+#             */
/*   Updated: 2021/07/18 00:14:19 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void	send_str(int pid, char *str)
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
*/
/*
void	pid_error(void)
{
	write(2, "Please check PID range.\n", 25);
}
*/
/*
void	send_char(int pid, char *message)
{

}

void	send_message(char *pid, char *message)
{
	int	pid;

	pid = ft_atoi(pid);
	while (*message != '\0')
	{
		send_char(pid, *message);
		message++;
	}
}
*/
void	usage_error(void)
{
	write(2, "usage: ./client [PID] [MESSAGE]\n", 32);
	exit(0);
}

#include <stdio.h>
void	my_handler(int signum)
{
	if (signum == SIGUSR1)
		//write(1, "Received SIGUSR1\n", 17);
		printf("👦🏻 Love you more\n");
}
int 	main(int argc, char **argv)
{
	if (argc != 3)
		usage_error();
	signal(SIGUSR1, my_handler);
	printf("PID: %d\n", getpid());
	while (1)
	{
		printf("👧🏻 I love you babe💕\n");
		sleep(1);
	}
	//send_message(argv[1], argv[2]);
	return (0);
	/*
	if (pid < 0 || pid > 32768)
		pid_error();
	*/
	/*
	if (is_num(argv[1]))
		pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	*/
}
