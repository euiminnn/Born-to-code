/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:35:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"
#include "core/error.h"
#include "utils/utils.h"

/**
 *
 * @example argv ['export', 'ABC=10']
 * @example argv ['export', 'ABC']
 * @example argv ['export']
 * @example argv ['export', 'ABC=10=10'] key : ABC, value : 10=10
 * @example argv ['export', 'ABC=10   =    10'] key : ABC, value : 10   =    10
 * @example argv ['export', 'ABC=10', 'BCE=20']
 *
 *
 */
static char	*to_string(t_env_data *data)
{
	if (!data->value)
		return (ft_strjoins((char *[3]){"declare -x ", data->key, "\n"}, 3));
	return (ft_strjoins((char *[6]){"declare -x ", data->key, \
				"=", "\"", data->value, "\"\n"}, 6));
}

void	builtin_export_only(int argc, char **argv, t_env *env, int fd)
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

int	_builtin_export(int argc, char **argv, t_env *env)
{
	char	*key;
	char	*value;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		ft_get_key_and_value(argv[i], &key, &value);
		if (ft_is_valid_key(key))
		{
			remove_env(env, key);
			insert_env(env, key, value);
		}
		else
		{
			error_message_for_export(argv[i]);
			flag = 1;
		}
		free(key);
		free(value);
		i++;
	}
	return (flag);
}

int	builtin_export(int argc, char **argv, t_env *env, int fd)
{
	char	*key;
	char	*value;
	int		flag;

	if (argc == 1)
	{
		builtin_export_only(argc, argv, env, fd);
		return (0);
	}
	flag = _builtin_export(argc, argv, env);
	return (flag);
}
