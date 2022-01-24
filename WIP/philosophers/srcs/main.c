/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:52 by echung            #+#    #+#             */
/*   Updated: 2022/01/19 20:43:33 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
#include "philo.h"

void	put_down(int id, t_philo *philo, t_global *g)
{
	pthread_mutex_lock(&(g->mutex_lock));
	philo[id].state = SLEEP;
	pthread_mutex_unlock(&(g->mutex_lock));
}

void	pick_up(int id, t_philo *philo, t_global *g)
{
	pthread_mutex_lock(&(g->mutex_lock));
	while (can_eat(id, philo) == FALSE)
	{
		usleep(100);
	}
	philo[id].state = EAT;
	pthread_mutex_unlock(&(g->mutex_lock));
}

int		can_eat(int id, t_philo *philo)
{
	if (philo[id].state == THINK \
		&& philo[left_of(id)].state != EAT
		&& philo[right_of(id)].state != EAT)
	{
		//philo[id].state = EAT;
		return (TRUE);
	}
	return (FALSE);
}

void	eat(int id, t_args *input)
{
	int	temp_time;
	int	time;

	time = input -> time_to_eat;
	temp_time = 23456;
	printf("%d philo%d is eating\n", temp_time, id);
	usleep(time * 1000);
}

void	think(int id)
{
	int	temp_time;

	temp_time = 12345;
	printf("%d philo%d is thinking\n", temp_time, id);
	usleep(100);
}

void	*philosopher(void *param)
{
	int	id;

	id = *((int *)param);
	while (TRUE)
	{
		think(id);
		pickup(id);
		eat(id);
		putdown(id);
	}
}

int		right_of_philo(int id, t_args *input)
{
	int	num;
	int	right_id;

	num = input -> number_of_philos;
	right_id = (id + 1) % num;
	return (right_id);
}

int		left_of_philo(int id, t_args *input)
{
	int	num;
	int	left_id;
	
	num = input -> number_of_philos;
	left_id = (id - 1 + num) % num;
	return (left_id);
}

void	create_thread(t_args *input)
{
	int	i;
	pthread_t	tid;

	i = 0;
	while (i < input->number_of_philos)
	{
		pthread_create(&tid, NULL, philosopher, (void *)&i);
		pthread_join(tid, NULL);
		i++;
	}
}

void	init_mutex(t_global *g)
{
	pthread_mutex_init(&(g->mutex_lock), NULL);
}

void	init_state(t_args *input, t_philo *philo)
{
	int	id;

	id = 0;
	while (id < input -> number_of_philos)
	{
		philo[id].state = THINK;
		id++;
	}
}

void	prepare_simulation(t_args *input)
{
	t_philo		philo[input -> number_of_philos];
	t_global	g;
	
	ft_bzero(&philo, sizeof(philo));
	ft_bzero(&g, sizeof(g));
	init_state(input, philo);
	init_mutex(&g);
	create_thread(input);
}

void	init_args(int argc, char **argv, t_args *input)
{
	input->number_of_philos = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->minimum_eat = ft_atoi(argv[5]);
	prepare_simulation(input);
}

#define ERROR 1
int	error_msg_args(void)
{
	char *error = "Check the required arguments.";
	write(2, error, ft_strlen(error));
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_args	input;
	
	ft_bzero(&input, sizeof(input));
	if (argc == 5 || argc == 6)
		init_args(argc, argv, &input);
	else
		return (error_msg_args());
	return (0);
}
