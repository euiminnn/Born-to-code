/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:48:04 by echung            #+#    #+#             */
/*   Updated: 2022/01/19 03:48:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_t_args(t_args *input)
{
	printf("num: %d\n", input->number_of_philos);
	printf("die: %d\n", input->time_to_die);
	printf("eat: %d\n", input->time_to_eat);
	printf("sleep: %d\n", input->time_to_sleep);
	printf("min: %d\n", input->minimum_eat);
}
