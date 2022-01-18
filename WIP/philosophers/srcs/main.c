/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:52 by echung            #+#    #+#             */
/*   Updated: 2022/01/19 02:14:29 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_t_args(t_args *input)
{
	printf("num: %d\n", input->number_of_philos);
	printf("die: %d\n", input->time_to_die);
	printf("eat: %d\n", input->time_to_eat);
	printf("sleep: %d\n", input->time_to_sleep);
	printf("min: %d\n", input->minimum_eat);
}

void	init_args(int argc, char **argv, t_args *input)
{
	input->number_of_philos = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->minimum_eat = ft_atoi(argv[5]);
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
	t_args	input;

	ft_bzero(&input, sizeof(input));
	if (argc == 5 || argc == 6)
		init_args(argc, argv, &input);
	else
		return (error_msg_args());
	print_t_args(&input);
	return (0);
}
