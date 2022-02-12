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

int	left_id(t_philo *philo)
{
	return (philo->id);
}

int	right_id(t_philo *philo)
{
	int	id_right;

	id_right = (philo->id + 1) % philo->input->number_of_philos;
	return (id_right);
}
