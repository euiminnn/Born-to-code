/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:52 by echung            #+#    #+#             */
/*   Updated: 2022/01/18 21:40:22 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"
#include <string.h>

void	save_with_option(char **argv)
{
	(void)argv;
}

void	save_without_option(char **argv)
{
	(void)argv;
}

void	init_args(int argc, char **argv)
{
	if (argc == 5)
		save_without_option(argv);
	save_with_option(argv);
}

#define ERROR 1
int	error_msg_args(void)
{
	char *error = "Check the required arguments.";
	write(2, error, strlen(error));
	return (ERROR);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		init_args(argc, argv);
	else
		return (error_msg_args());
	return (0);
}
