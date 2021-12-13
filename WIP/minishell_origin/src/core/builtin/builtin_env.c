/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:40 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 19:57:03 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"
#include "core/error.h"

static char	*to_string(t_env_data *data)
{
	if (!data->value)
		return (NULL);
	return (ft_strjoins((char *[4]){data->key, "=", data->value, "\n"}, 4));
}

static void	print_env_list(t_env *env, int fd)
{
	char	**envp;
	int		i;

	i = 0;
	envp = to_string_env(env, to_string);
	while (envp[i])
	{
		ft_putstr_fd(envp[i], fd);
		i++;
	}
}

static int	_builtin_env(char **argv, t_env *env, int fd)
{
	char	*key_and_value[2];
	int		i;

	i = 0;
	while (argv[++i])
	{
		ft_get_key_and_value(argv[i], &key_and_value[0], &key_and_value[1]);
		if (!key_and_value[1])
		{
			error_message_for_env(key_and_value[0]);
			free(key_and_value[0]);
			free(key_and_value[1]);
			return (127);
		}
		free(key_and_value[0]);
		free(key_and_value[1]);
	}
	print_env_list(env, fd);
	i = 0;
	while (argv[++i])
	{
		ft_putstr_fd(argv[i], fd);
		ft_putstr_fd("\n", fd);
	}
	return (0);
}

int	builtin_env(int argc, char **argv, t_env *env, int fd)
{
	if (argc == 1)
	{
		print_env_list(env, fd);
		return (0);
	}
	else if (argc > 1)
		return (_builtin_env(argv, env, fd));
	return (0);
}
