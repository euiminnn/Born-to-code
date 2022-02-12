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

int	meet_minimum_eat(t_philo *philo)
{
	int		count;
	int		i;

	if (!philo->input->minimum_eat)
		return (0); //minimum_eat이라는 5번째 인자가 존재하지 않는 경우
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
		process_message(philo, END);
		return (1); //minimum_eat이 존재하고, 조건을 충족한 경우
	}
	return (0); //minimum_eat이 존재하나, 조건을 충족하지 않은 경우
}

int	is_time_to_die(t_philo *philo)
{
	int		pnow;
	int		i;

	i = 0;
	while (i < philo->input->number_of_philos)
	{
		pnow = get_time_in_ms() - philo[i].input->clock;
		if (pnow - philo[i].last_eat > philo[i].input->time_to_die)
		{
			process_message(philo, DIE);
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
			exit(0);
		}
		if (meet_minimum_eat(philo))
		{
			exit(0); //대신에 return 0 하고, main에서 monitor가 0이면 join 후 리턴해서 프로그램 종료
		}
		usleep(200);
	}
	return (0);
}
