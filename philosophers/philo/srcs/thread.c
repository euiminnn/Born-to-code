/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:00:32 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 16:00:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_end_signal(t_philo *philo)
{
	if (philo->end_signal)
	{
		return (1);
	}
	return (0);
}

static void	*philosopher(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (!get_end_signal(philo))
	{
		eat(philo);
		do_sleep(philo);
		think(philo);
		usleep(200);
	}
	return (0);
}

void	create_thread(t_philo *philo)
{
	int			i;
	pthread_t	tid_m;

	i = 0;
	while (i < philo->input->number_of_philos)
	{
		pthread_create(&(philo[i].tid), NULL, philosopher, (void *)(&philo[i]));
		i++;
	}
	pthread_create(&tid_m, NULL, monitor, (void *)(philo));
	if (philo->input->number_of_philos == 1)
		pthread_detach(philo[0].tid);
	else
	{
		i = 0;
		while (i < philo->input->number_of_philos)
		{
			pthread_join(philo[i].tid, NULL);
			i++;
		}
	}
	pthread_join(tid_m, NULL);
}
