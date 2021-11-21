/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/26 17:31:08 by echung           ###   ########.fr       */
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

static int	is_invalid_id(char *arg, char *key, char *value)
{
	(void) arg;
	if (!key || key[0] == '\0')
		return (1);
	if ('0' <= key[0] && key[0] <= '9')
		return (1);
	while (*key)
	{
		if (!(('a' <= *key && *key <= 'z') || ('A' <= *key && *key <= 'Z')
				|| ('0' <= *key && *key <= '9')))
			return (1);
		key++;
	}
	return (0);
}

void	error_message_for_export(char **argv)
{
	ft_putstr_fd("minishell: export: \`", 2);
	ft_putstr_fd(*argv, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
}

int	_builtin_export(int argc, char **argv, t_env *env)
{
	char	*key_and_value[2];
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		ft_get_key_value(argv[i], &key_and_value[0], &key_and_value[1]);
		if (is_invalid_id(argv[i], key_and_value[0], key_and_value[1]))
		{
			error_message_for_export(&argv[i]);
			flag = 1;
		}
		else
		{
			remove_env(env, key_and_value[0]);
			insert_env(env, key_and_value[0], key_and_value[1]);
		}
		free(key_and_value[0]);
		free(key_and_value[1]);
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
