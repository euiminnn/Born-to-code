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
		think(philo->id);
		pick_up(philo->id);
		eat(philo->id, philo->input);
		put_down(philo->id);
		do_sleep(philo->id);
	}
}

void	create_thread(t_args *input, t_philo *philo)
{
	int	i;
	pthread_t	tid;

	i = 0;
	while (i < input->number_of_philos)
	{
        philo[i].id = i;
        philo[i].input = input;
        philo[i].philo = philo; 
		pthread_create(&tid, NULL, philosopher, (void *)&philo[i]);
		pthread_join(tid, NULL);
		i++;
	}
}
