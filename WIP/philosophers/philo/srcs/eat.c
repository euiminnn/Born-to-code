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
	pthread_mutex_lock(&(philo->fork));
	while (can_eat(id, philo) == FALSE)
	{
		usleep(100);
	}
	philo[id].state = EAT;
	pthread_mutex_unlock(&(philo->fork));
}

int		can_eat(int id, t_philo *philo)
{
	if (philo[id].state == THINK \
		&& philo[left_of_philo(id, philo)].state != EAT
		&& philo[right_of_philo(id, philo)].state != EAT)
	{
		//philo[id].state = EAT;
		return (TRUE);
	}
	return (FALSE);
}

void	eat(int id, t_philo *philo)
{
	int	now;
	int	time;

	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	printf("%d philo%d is eating\n", now - philo->input->clock, id);
	usleep(time * 1000);
}
