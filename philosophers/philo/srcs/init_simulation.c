/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:49:37 by echung            #+#    #+#             */
/*   Updated: 2022/02/13 03:49:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	id;

	id = 0;
	while (id < philo->input->number_of_philos)
	{
		philo[id].fork = fork;
		pthread_mutex_init(&(philo[id].fork[id]), NULL);
		id++;
	}
}

static void	init_printer(t_philo *philo, pthread_mutex_t *printer)
{
	int	id;

	id = 0;
	while (id < philo->input->number_of_philos)
	{
		philo[id].printer = printer;
		id++;
	}
}

static void	init_philo_elements(t_philo *philo, t_args *input)
{
	int	i;

	i = 0;
	while (i < input->number_of_philos)
	{
		philo[i].input = input;
		philo[i].id = i;
		philo[i].last_eat = 0;
		philo[i].eat_count = 0;
		philo[i].end_signal = 0;
		i++;
	}
}

void	init_simulation(t_args *input)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	printer;

	pthread_mutex_init(&printer, NULL);
	philo = (t_philo *)malloc(sizeof(t_philo) * input->number_of_philos);
	if (!philo)
		return ;
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* input->number_of_philos);
	if (!fork)
		return ;
	ft_bzero(philo, sizeof(philo));
	init_philo_elements(philo, input);
	init_fork(philo, fork);
	init_printer(philo, &printer);
	create_thread(philo);
	end_simulation(philo, &printer);
}
