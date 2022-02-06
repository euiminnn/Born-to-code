/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:00 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:47:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down(int id, t_philo *philo, t_global *g)
{
	pthread_mutex_lock(&(g->mutex_lock));
	philo[id].state = SLEEP;
	pthread_mutex_unlock(&(g->mutex_lock));
}

void	pick_up(int id, t_philo *philo, t_global *g)
{
	pthread_mutex_lock(&(g->mutex_lock));
	while (can_eat(id, philo) == FALSE)
	{
		usleep(100);
	}
	philo[id].state = EAT;
	pthread_mutex_unlock(&(g->mutex_lock));
}

int		can_eat(int id, t_philo *philo)
{
	if (philo[id].state == THINK \
		&& philo[left_of_philo(id)].state != EAT
		&& philo[right_of_philo(id)].state != EAT)
	{
		//philo[id].state = EAT;
		return (TRUE);
	}
	return (FALSE);
}

void	eat(int id, t_args *input)
{
	int	temp_time;
	int	time;

	time = input -> time_to_eat;
	temp_time = 23456;
	printf("%d philo%d is eating\n", temp_time, id);
	usleep(time * 1000);
}
