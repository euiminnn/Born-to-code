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

void	*philosopher(void *philo_void)
{
	t_philo *philo;

	philo = (t_philo *)philo_void;
	while (TRUE)
	{
		eat(philo);
		do_sleep(philo->id, philo);
		think(philo->id, philo);
		usleep(200);
	}

}

void	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->number_of_philos)
	{
        // philo[i].id = i;
		// printf("id: %d\n", i);
		pthread_create(&(philo[i].tid), NULL, philosopher, (void *)(&philo[i]));
		i++;
	}
	i = 0;
	while (i < philo->input->number_of_philos)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
}
