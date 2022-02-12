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

void	init_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int id;

	id = 0;
	while (id < philo->input->number_of_philos)
	{
		philo[id].fork = fork;
		pthread_mutex_init(&(philo[id].fork[id]), NULL);
		id++;
	}
}

void	init_state(t_philo *philo)
{
	int	id;

	id = 0;
	while (id < philo->input->number_of_philos)
	{
		philo[id].state = THINK;
		id++;
	}
}

void	init_id(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->input->number_of_philos)
	{
		philo[i].id = i;
		i++;
	}
}

void	init_input(t_philo *philo, t_args *input)
{
	int i;

	i = 0;
	while (i < input->number_of_philos)
	{
		philo[i].input = input;
		i++;
	}
}

void	init_last_eat(t_philo *philo, t_args *input)
{
	int i;

	i = 0;
	while (i < input->number_of_philos)
	{
		philo[i].last_eat = 0;
		i++;
	}
}

void	init_simulation(t_args *input)
{
	t_philo			philo[input->number_of_philos];
	pthread_mutex_t	fork[input->number_of_philos];
	
	ft_bzero(philo, sizeof(philo));

	init_input(philo, input);
	init_last_eat(philo, input);
	init_id(philo);
	init_state(philo);

	init_fork(philo, fork);
	create_thread(philo);
}

int	check_input(t_args *input, int argc)
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
	init_simulation(input);
	return (TRUE);
}
