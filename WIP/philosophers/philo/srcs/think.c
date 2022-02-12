/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:56:39 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:56:45 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	process_message(philo, THINK);
	// int	now;

	// now = get_time_in_ms();
	// printf("%d %d is thinking\n", now - philo->input->clock, id+1);
}
