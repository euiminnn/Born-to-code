/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 05:16:22 by echung            #+#    #+#             */
/*   Updated: 2022/02/13 05:16:26 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_philo *philo)
{
	int	id;

	id = 0;
    while (id < philo->input->number_of_philos)
    {
        pthread_mutex_destroy(&(philo[id].fork[id]));
        // free(philo[id].fork);
        id++;
    }
    if (philo->fork)
        free(philo->fork);
	id = 0;
	while (id < philo->input->number_of_philos)
	{
		pthread_mutex_destroy(philo[id].printer);
		id++;
	}
    if (philo)
        free(philo);
}
