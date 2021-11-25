/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:19 by echung            #+#    #+#             */
/*   Updated: 2021/11/23 19:20:51 by echung           ###   ########.fr       */
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

static int	valid_key(t_env *env, char *key)
{
	if (search_env(env, key))
		return (1);
	else
		return (0);
}

static void	_builtin_echo(int argc, char **argv, t_env *env, int fd)
{
	int	s;

	(void)env;
	s = string_start(argc, argv);
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
}

/*
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
			if (ft_strlen(argv[s+1]) > 0 || valid_key(env, argv[s+1]))
			{
				ft_putstr_fd(argv[s], fd);
				ft_putstr_fd(" ", fd);
			}
			else
				ft_putstr_fd(argv[s], fd);
		}
		else
			ft_putstr_fd(argv[s], fd);
		s++;
	}
}
*/
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
