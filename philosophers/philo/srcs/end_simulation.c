/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 05:16:22 by echung            #+#    #+#             */
/*   Updated: 2022/02/14 15:10:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_philo *philo, pthread_mutex_t *printer)
{
	int	id;

	id = 0;
	while (id < philo->input->number_of_philos)
	{
		pthread_mutex_destroy(&(philo[id].fork[id]));
		id++;
	}
	if (philo->fork)
		free(philo->fork);
	pthread_mutex_destroy(printer);
	if (philo)
		free(philo);
}
