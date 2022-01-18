/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:41:52 by echung            #+#    #+#             */
/*   Updated: 2022/01/19 03:54:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include "libft.h"

typedef struct	s_args {
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	minimum_eat;
}	t_args;

typedef enum	e_state {
	EAT = 0,
	THINK,
	SLEEP
}	t_state;

typedef struct	s_global {
	pthread_mutex_t	mutex_lock;
}	t_global;

#endif
