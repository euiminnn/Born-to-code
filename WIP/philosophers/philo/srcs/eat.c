/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:00 by echung            #+#    #+#             */
/*   Updated: 2022/02/13 02:53:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	put_down(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork[left_id(philo)]));
	pthread_mutex_unlock(&(philo->fork[right_id(philo)]));
}

static void	pick_up(t_philo *philo)
{
	int	time;
	int	first_round;

	time = philo->input->time_to_eat;
	first_round = get_time_in_ms() - philo->input->clock;
	if (first_round < 10 && (philo->id + 1) % 2 == 0)
		wait_until(get_time_in_ms() + time);
	pthread_mutex_lock(&(philo->fork[left_id(philo)]));
	process_message(philo, FORK);
	pthread_mutex_lock(&(philo->fork[right_id(philo)]));
	process_message(philo, FORK);
}

void	eat(t_philo *philo)
{
	int	now;
	int	time;

	pick_up(philo);
	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	philo->last_eat = now - philo->input->clock;
	process_message(philo, EAT);
	wait_until(get_time_in_ms() + time);
	put_down(philo);
	philo->eat_count++;
}
