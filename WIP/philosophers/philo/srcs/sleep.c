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

void	do_sleep(t_philo *philo)
{
	int	time;

	time = philo -> input -> time_to_sleep;
	process_message(philo, SLEEP);
	wait_until(get_time_in_ms() + time);
}
