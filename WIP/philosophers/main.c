/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:52 by echung            #+#    #+#             */
/*   Updated: 2021/12/16 23:39:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>

void	save_with_option(char **argv)
{
	(void)argv;
}

void	save(char **argv)
{
	(void)argv;
}

void	init_args(int argc, char **argv)
{
	if (argc == 5)
		save(argv);
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
