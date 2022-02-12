/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:52 by echung            #+#    #+#             */
/*   Updated: 2022/02/06 15:39:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg_args(void)
{
	char	*error;

	error = "Check the input arguments.\n";
	write(2, error, ft_strlen(error));
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_args	input;

	ft_bzero(&input, sizeof(input));
	if (argc == 5 || argc == 6)
	{
		if (init_args(argc, argv, &input) == ERROR)
			return (error_msg_args());
		return (0);
	}
	else
		return (error_msg_args());
}
