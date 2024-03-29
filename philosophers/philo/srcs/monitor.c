/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:29:28 by echung            #+#    #+#             */
/*   Updated: 2022/02/13 03:29:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	send_end_signal(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->number_of_philos)
	{
		philo[i].end_signal = 1;
		i++;
	}
}

static int	meet_minimum_eat(t_philo *philo)
{
	int		count;
	int		i;

	if (!philo->input->minimum_eat)
		return (0);
	i = 0;
	count = 0;
	while (i < philo->input->number_of_philos)
	{
		if (philo[i].eat_count >= philo->input->minimum_eat)
			count++;
		i++;
	}
	if (count == philo->input->number_of_philos)
	{
		process_message(&philo[0], END);
		send_end_signal(philo);
		return (1);
	}
	return (0);
}

static int	is_time_to_die(t_philo *philo)
{
	int		pnow;
	int		i;

	i = 0;
	while (i < philo->input->number_of_philos)
	{
		pnow = get_time_in_ms() - philo[i].input->clock;
		if (pnow - philo[i].last_eat > philo[i].input->time_to_die)
		{
			process_message(&philo[i], DIE);
			send_end_signal(philo);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (TRUE)
	{
		if (is_time_to_die(philo))
		{
			return (0);
		}
		if (meet_minimum_eat(philo))
		{
			return (0);
		}
		usleep(200);
	}
	return (0);
}
