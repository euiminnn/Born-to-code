/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:51:01 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:51:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo *philo)
{
	pthread_mutex_init(&(philo->fork), NULL);
}

void	init_state(t_philo *philo)
{
	int	id;

	id = 0;
	while (id < philo -> input -> number_of_philos)
	{
		philo[id].state = THINK;
		id++;
	}
}

void	init_simulation(t_args *input)
{
	t_philo		philo[input -> number_of_philos];
	// t_global	g;
	
	ft_bzero(&philo, sizeof(philo));
	// ft_bzero(&g, sizeof(g));
	philo->input = input;
	init_state(philo);
	init_mutex(philo);
	create_thread(philo);
}

void	init_args(int argc, char **argv, t_args *input)
{
	input->number_of_philos = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->minimum_eat = ft_atoi(argv[5]);
	init_simulation(input);
}
