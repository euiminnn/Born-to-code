/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:19 by echung            #+#    #+#             */
/*   Updated: 2021/10/26 16:30:40 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"

static int	valid_n(char *n_option)
{
	char	*ptr;

	ptr = n_option;
	if (*ptr == '-')
	{
		ptr++;
		if (!(*ptr))
			return (FALSE);
		while (*ptr)
		{
			if (*ptr != 'n')
				return (FALSE);
			ptr++;
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	string_start(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (valid_n(argv[i]) == FALSE)
			return (i);
		i++;
	}
	return (i);
}

static void	_builtin_echo(int argc, char **argv, t_env *env, int fd)
{
	int	s;

	(void)env;
	s = string_start(argc, argv);
	while (s < argc)
	{
		if (!*argv[s])
		{
			s++;
			continue ;
		}
		if (s != argc - 1)
		{
			ft_putstr_fd(argv[s], fd);
			ft_putstr_fd(" ", fd);
		}
		else
			ft_putstr_fd(argv[s], fd);
		s++;
	}
}

int	builtin_echo(int argc, char **argv, t_env *env, int fd)
{
	int	n_option;

	(void)env;
	n_option = 1;
	if (argc == 1)
	{
		write(fd, "\n", 1);
		return (0);
	}
	_builtin_echo(argc, argv, env, fd);
	if (valid_n(argv[1]) == FALSE)
		n_option = 0;
	if (!n_option)
		ft_putstr_fd("\n", fd);
	return (0);
}
