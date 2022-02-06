/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:54:52 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:54:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		right_of_philo(int id, t_philo *philo)
{
	int	num;
	int	right_id;

	num = philo -> input -> number_of_philos;
	right_id = (id + 1) % num;
	return (right_id);
}

int		left_of_philo(int id, t_philo *philo)
{
	int	num;
	int	left_id;
	
	num = philo -> input -> number_of_philos;
	left_id = (id - 1 + num) % num;
	return (left_id);
}
