/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:19 by echung            #+#    #+#             */
/*   Updated: 2021/10/19 18:35:53 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"
#include <stdio.h>

int valid_n(char *n_option)
{
	char *ptr;

	ptr = n_option;
	if (*ptr == '-')
	{
		ptr++;
		if (!(*ptr))
			return (-1);
		while (*ptr)
		{
			if (*ptr != 'n')
				return (-1);
			ptr++;
		}
		return (0);
	}
	else
		return (-1);
}

int	string_start(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		if (valid_n(argv[i]))
			return i;	// -n 뒤의 index 반환
		i++;
	}
	return i;
}

int	builtin_echo(int argc, char **argv, t_env *env, int fd)
{
	(void)env;
	int n_option;
	int s;

	n_option = 1;
	s = string_start(argc, argv);

	/*
	if (argc == 1)		//echo ->echo인지는 이 전에 확인하고 여기로 넘어오는지?
	{
		write(fd, "\n", 1);
		return (0);
	}
	if ((argc == 2) && (valid_n(argv[1]) == 0))		//echo -n
	{
		return (0);
	}
	*/
	if (valid_n(argv[1]) != 0)	//without n option
		n_option = 0;
	while (s < argc)
	{
		if (s != argc - 1)
    {
      ft_putstr_fd(argv[s], fd);
			ft_putstr_fd(" ", fd);
    }
		else
			ft_putstr_fd(argv[s], fd);
		s++;
	}
	if (!n_option)
		ft_putstr_fd("\n", fd);
	return (0);
}
