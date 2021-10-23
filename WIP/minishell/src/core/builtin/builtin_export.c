/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/24 02:31:14 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"

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
	return (ft_strjoins((char *[6]){"declare -x ", data->key, "=", "\"", data->value, "\"\n"}, 6));
}

void	builtin_export_only(int argc, char **argv, t_env *env, int fd)
{
	char	**envp;
	int i;

	i = 0;
	envp = to_string_env(env, to_string);
	while (envp[i])
	{
		ft_putstr_fd(envp[i], fd);
		i++;
	}
}

int	builtin_export(int argc, char **argv, t_env *env, int fd)
{
	char *key;
	char *value;
	int	i;

	if (argc == 1)	//export만 들어온 경우
	{
		builtin_export_only(argc, argv, env, fd);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		ft_get_key_value(argv[i], &key, &value);
		insert_env(env, key, value);
		free(key);
		free(value);
		i++;
	}
	return (0);
}
