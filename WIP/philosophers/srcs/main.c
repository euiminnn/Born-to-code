/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:52 by echung            #+#    #+#             */
/*   Updated: 2022/01/19 00:14:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	write(2, error, ft_strlen(error));
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
