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

int		get_end_signal(t_philo *philo)
{
	int i;
	// int	end;

	i = 0;
	// end = 0;
	while (i < philo->input->number_of_philos)
	{
		if (philo[0].end_signal)
		{
			printf("philo%d I GOT END SIGNAL %d\n", i, philo[i].end_signal);
			return (1);
		}
		i++;
	}
	return (0);
	// if (end)
	// 	return (1);

/*
	if (philo->end_signal)
		return (1);
	return (0);
*/
}

void	*philosopher(void *philo_void)
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
	i = 0;
	while (i < philo->input->number_of_philos)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	pthread_join(tid_m, NULL);
}
