/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:56:26 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:56:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_sleep(int id, t_philo *philo)
{
	int	time;
	int	now;

	philo[id].state = SLEEP;
	time = philo -> input -> time_to_sleep;
	now = get_time_in_ms();
	printf("%d %d is sleeping\n", now - philo -> input -> clock, id+1);
	usleep(time * 1000);
}
