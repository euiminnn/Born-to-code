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

static char	*print_message(t_state state)
{
	if (state == FORK)
		return (" has taken a fork\n");
	else if (state == EAT)
		return (" is eating\n");
	else if (state == THINK)
		return (" is thinking\n");
	else if (state == SLEEP)
		return (" is sleeping\n");
	else if (state == DIE)
		return (" died\n");
	else
		return ("Simulation ended\n");
}

void	process_message(t_philo *philo, t_state state)
{
	static int	finish = FALSE;

	pthread_mutex_lock(philo->printer);
	if (!finish)
	{
		ft_putnbr_fd(get_time_in_ms() - philo->input->clock, 1);
		write(1, " ", 1);
		if (state != END)
			ft_putnbr_fd(philo->id + 1, 1);
		if (state == DIE || state == END)
			finish = TRUE;
		write(1, print_message(state), ft_strlen(print_message(state)));
	}
	pthread_mutex_unlock(philo->printer);
}
