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
	int	temp_time;

	time = philo -> input -> time_to_sleep;
	temp_time = 12345;
	printf("%d philo%d is sleeping\n", temp_time, id);
	usleep(time * 1000);
}
