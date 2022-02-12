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
	pthread_mutex_unlock(&(philo->fork[left_id(philo)]));
	pthread_mutex_unlock(&(philo->fork[right_id(philo)]));
}

void	pick_up(t_philo *philo)
{
	int	now;
	int	time;
	
	time = philo->input->time_to_eat;
	if ((philo->id + 1) % 2 == 0)
		wait_until(get_time_in_ms() + time);
	pthread_mutex_lock(&(philo->fork[left_id(philo)]));
	now = get_time_in_ms();
	printf("%d %d has taken a fork\n", now - philo->input->clock, philo->id+1);
	pthread_mutex_lock(&(philo->fork[right_id(philo)]));
	now = get_time_in_ms();
	printf("%d %d has taken a fork\n", now - philo->input->clock, philo->id+1);
	philo->state = EAT;
}

void	eat(t_philo *philo)
{
	int	now;
	int	time;

	pick_up(philo);
	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	philo->last_eat = now - philo->input->clock;
	printf("%d %d is eating\n", now - philo->input->clock, philo->id+1);
	wait_until(get_time_in_ms() + time);
	put_down(philo);
}

void	*monitor(void *philo_void)
{
	t_philo	*philo;
	int pnow;
	int i;

	philo = (t_philo *)philo_void;
	while (TRUE)
	{
		i = 0;
		while (i < philo->input->number_of_philos)
		{
			
			pnow = get_time_in_ms() - philo[i].input->clock;
			if (pnow - philo[i].last_eat > philo[i].input->time_to_die)
			{
				printf("%d %d died\n", pnow, i+1);
				exit(0);
			}
			i++;
		}
		usleep(200);
	}
}
