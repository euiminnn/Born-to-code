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

void	think(int id)
{
	int	temp_time;

	temp_time = 12345;
	printf("%d philo%d is thinking\n", temp_time, id);
	usleep(100);
}
