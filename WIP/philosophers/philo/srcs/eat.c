/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:00 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:47:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork[left_id(philo)]));
	pthread_mutex_unlock(&(philo->fork[right_id(philo)]));
}

void	pick_up(t_philo *philo)
{
	// int	now;
	int	time;
	int	first_round;
	
	time = philo->input->time_to_eat;
	first_round = get_time_in_ms() - philo->input->clock;
	if (first_round < 10 && (philo->id + 1) % 2 == 0)
		wait_until(get_time_in_ms() + time);
	pthread_mutex_lock(&(philo->fork[left_id(philo)]));
	// now = get_time_in_ms();
	process_message(philo, FORK);
	// printf("%d %d has taken a fork\n", now - philo->input->clock, philo->id+1);
	pthread_mutex_lock(&(philo->fork[right_id(philo)]));
	// now = get_time_in_ms();
	process_message(philo, FORK);
	// printf("%d %d has taken a fork\n", now - philo->input->clock, philo->id+1);
	// philo->state = EAT;
}

void	eat(t_philo *philo)
{
	int	now;
	int	time;

	pick_up(philo);
	time = philo->input->time_to_eat;
	now = get_time_in_ms();
	philo->last_eat = now - philo->input->clock;
	process_message(philo, EAT);
	// printf("%d %d is eating\n", now - philo->input->clock, philo->id+1);
	wait_until(get_time_in_ms() + time);
	put_down(philo);
	philo->eat_count++;
}

void	*monitor(void *philo_void)
{
	t_philo	*philo;
	int pnow;
	int i;
	int	count;

	philo = (t_philo *)philo_void;
	while (TRUE)
	{
		i = 0;
		while (i < philo->input->number_of_philos)
		{
			pnow = get_time_in_ms() - philo[i].input->clock;
			if (pnow - philo[i].last_eat > philo[i].input->time_to_die)
			{
				process_message(philo, DIE);
				// printf("%d %d died\n", pnow, i + 1);
				exit(0);
			}
			i++;
		}
		count = 0;
		if (philo->input->minimum_eat)
		{
			i = 0;
			while (i < philo->input->number_of_philos)
			{
				if (philo[i].eat_count >= philo->input->minimum_eat)
					count++;
				i++;
			}
			if (count == philo->input->number_of_philos)
			{
				process_message(philo, END);
				// printf("Simulation ended\n");
				exit(0); //대신에 return 0 하고, main에서 monitor가 0이면 join 후 리턴해서 프로그램 종료
			}
		}
		usleep(200);
	}
}
