/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:41:52 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:39:53 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

# define ERROR 0
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAILURE 0

typedef struct	s_args {
	int	clock;
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

typedef struct	s_philo {
	int				id;
	t_args			*input;
	t_state 		state;
	pthread_mutex_t	fork;
}	t_philo;

// typedef struct	s_global {
// 	pthread_mutex_t	mutex_lock;
// }	t_global;

int		get_time_in_ms(void);
void	eat(int id, t_philo *philo);
int		can_eat(int id, t_philo *philo);
void	pick_up(int id, t_philo *philo);
void	put_down(int id, t_philo *philo);
int		init_args(int argc, char **argv, t_args *input);
int		check_input(t_args *input, int argc);
void	init_simulation(t_args *input);
void	init_state(t_philo *philo);
void	init_mutex(t_philo *philo);
int		left_of_philo(int id, t_philo *philo);
int		right_of_philo(int id, t_philo *philo);
void	think(int id, t_philo *philo);
void	do_sleep(int id, t_philo *philo);
void	create_thread(t_philo *philo);
void	*philosopher(void *param);

#endif
