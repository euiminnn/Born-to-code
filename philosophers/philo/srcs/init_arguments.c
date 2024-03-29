/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:51:01 by echung            #+#    #+#             */
/*   Updated: 2022/02/13 03:31:55 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_input(t_args *input, int argc)
{
	if (input->number_of_philos <= 0)
		return (ERROR);
	if (input->time_to_die <= 0)
		return (ERROR);
	if (input->time_to_eat <= 0)
		return (ERROR);
	if (input->time_to_sleep <= 0)
		return (ERROR);
	if (argc == 6 && input->minimum_eat <= 0)
		return (ERROR);
	return (TRUE);
}

int	init_args(int argc, char **argv, t_args *input)
{
	input->clock = get_time_in_ms();
	input->number_of_philos = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->minimum_eat = ft_atoi(argv[5]);
	if (check_input(input, argc) == ERROR)
		return (ERROR);
	return (TRUE);
}
