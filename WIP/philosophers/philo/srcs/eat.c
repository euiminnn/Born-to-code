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

void	put_down(t_philo *philo)
{
	philo[left_id(philo)].fork_on_table = NOTINUSE;
	philo[right_id(philo)].fork_on_table = NOTINUSE;
	pthread_mutex_unlock(&(philo[left_id(philo)].fork));
	pthread_mutex_unlock(&(philo[right_id(philo)].fork));
}

void	pick_up(t_philo *philo)
{
	pthread_mutex_lock(&(philo[left_id(philo)].fork));
	pthread_mutex_lock(&(philo[right_id(philo)].fork));
	while (can_eat(philo) == FALSE)
	{
		usleep(5000);
	}
	philo[left_id(philo)].fork_on_table = INUSE;
	philo[right_id(philo)].fork_on_table = INUSE;
	philo[philo->id].state = EAT;
}

int		can_eat(t_philo *philo)
{
	// if (philo[philo->id].state == THINK
	if (philo[left_id(philo)].fork_on_table == NOTINUSE \
		&& philo[right_id(philo)].fork_on_table == NOTINUSE)
	{
		return (TRUE);
	}
	return (FALSE);
}

void	eat(t_philo *philo)
{
	int	now;
	int	time;

	pick_up(philo);
	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	printf("%d philo%d is eating\n", now - philo->input->clock, philo->id);
	usleep(time * 1000);
	put_down(philo);
}
