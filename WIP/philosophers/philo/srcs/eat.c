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
	// philo->fork_on_table[left_id(philo)] = NOTINUSE;
	// philo->fork_on_table[right_id(philo)] = NOTINUSE;
	pthread_mutex_unlock(&(philo->fork[left_id(philo)]));
	pthread_mutex_unlock(&(philo->fork[right_id(philo)]));
}

void	pick_up(t_philo *philo)
{
	int	now;

	pthread_mutex_lock(&(philo->fork[left_id(philo)]));
	pthread_mutex_lock(&(philo->fork[right_id(philo)]));
	// while (can_eat(philo) == FALSE)
	// {
	// 	printf("sleep??\n");
	// 	usleep(5000);
	// }
	// philo->fork_on_table[left_id(philo)] = INUSE;
	now = get_time_in_ms();

	printf("%d %d has taken a fork\n", now - philo->input->clock, philo->id+1);
	// philo->fork_on_table[right_id(philo)] = INUSE;
	now = get_time_in_ms();

	printf("%d %d has taken a fork\n", now - philo->input->clock, philo->id+1);
	philo->state = EAT;
}
/*
int		can_eat(t_philo *philo)
{
	// if (philo[philo->id].state == THINK
	if (philo->fork_on_table[left_id(philo)] == NOTINUSE \
		&& philo->fork_on_table[right_id(philo)] == NOTINUSE)
	{
		return (TRUE);
	}
	return (FALSE);
}
*/
void	eat(t_philo *philo)
{
	int	now;
	int	time;

	pick_up(philo);
	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	printf("%d %d is eating\n", now - philo->input->clock, philo->id+1);
	usleep(time * 1000);
	put_down(philo);
}
