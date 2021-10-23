/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/23 15:46:45 by echung           ###   ########.fr       */
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
		return (NULL);
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

	if (argc == 1)	//export만 들어온 경우
	{
		builtin_export_only(argc, argv, env, fd);
		return (0);
	}
	ft_get_key_value(argv[1], &key, &value);
    insert_env(env, key, value);
	free(key);
	free(value);
	return (0);
}
