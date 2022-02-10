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

void	put_down(int id, t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	philo[id].state = SLEEP;
	pthread_mutex_unlock(&(philo->fork));
}

void	pick_up(int id, t_philo *philo)
{
	pthread_mutex_lock(&(left_fork_of(philo)));
	pthread_mutex_lock(&(right_fork_of(philo)));
	while (can_eat(id, philo) == FALSE)
	{
		usleep(100);
	}
	left_of(philo[id].fork) = AVAILABLE;
	right_of(philo[id].fork) = AVAILABLE;
	philo[id].state = EAT;
	pthread_mutex_unlock(&(philo[id].fork));
	pthread_mutex_unlock(&(philo[id+1].fork));
}

int		left_fork_of(t_philo *philo)
{
	if (philo[id].fork == AVAILABLE)
		return (AVAILABLE);
	return (UNAVAILABLE);
}

int		right_fork_of(t_philo *philo)
{
	int	id_right;

	id_right = (philo->id + 1) % philo->input->number_of_philos;
	if (philo[id_right].fork == AVAILABLE)
		return (AVAILABLE);
	return (UNAVAILABLE);
}

int		can_eat(int id, t_philo *philo)
{
	if (left_fork_of(philo) == AVAILABLE; \
		&& right_fork_of(philo) == AVAILABLE; \
		philo[id].state == THINK
	{
		return (TRUE);
	}
	return (FALSE);
}

void	eat(int id, t_philo *philo)
{
	int	now;
	int	time;

	pick_up(id, philo);
	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	printf("%d philo%d is eating\n", now - philo->input->clock, id);
	usleep(time * 1000);
	put_down(id, philo);
}
