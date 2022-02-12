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

//error -1로 바꾸기
# define ERROR 0
# define TRUE 1
# define FALSE 0
# define INUSE 1
# define NOTINUSE 0

typedef struct s_args {
	int	clock;
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	minimum_eat;
}	t_args;

typedef enum e_state {
	FORK = 0,
	EAT,
	THINK,
	SLEEP,
	DIE,
	END
}	t_state;

typedef struct s_philo {
	t_args			*input;
	int				id;
	int				last_eat;
	int				eat_count;
	pthread_t		tid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*printer;
}	t_philo;

int		get_time_in_ms(void);
void	wait_until(int	time);

void	eat(t_philo *philo);
int		can_eat(t_philo *philo);
void	pick_up(t_philo *philo);
void	put_down(t_philo *philo);
int		init_args(int argc, char **argv, t_args *input);
int		check_input(t_args *input, int argc);
void	init_simulation(t_args *input);
void	init_mutex(t_philo *philo);

int		left_id(t_philo *philo);
int		right_id(t_philo *philo);

void	think(t_philo *philo);
void	do_sleep(t_philo *philo);
void	create_thread(t_philo *philo);
void	*philosopher(void *param);

void	*monitor(void *philo_void);
int		is_time_to_die(t_philo *philo);
int		meet_minimum_eat(t_philo *philo);

void	process_message(t_philo *philo, t_state state);

#endif
