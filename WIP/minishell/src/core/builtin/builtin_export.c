/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/24 03:07:20 by echung           ###   ########.fr       */
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

static int	is_invalid_id(char *arg, char *key, char *value)
{
	(void) arg;
	if (!key && value)
		return (1);
//	if (key && !value && sign)
//		return (1); //	-> 지금은 sign 관계없이 key만 있는 경우는 따로 처리하므로 sign이 있는지 확인하는 함수 필요 -> return 1 오류 아님....A= 는 env에 기록되네 ㅠ
	while (*key)
	{
		if (!('a' <= *key && *key <= 'z') || !('A' <= *key && *key <= 'Z'))
			return (1);
		key++;
	}
	return (0);
}

int	builtin_export(int argc, char **argv, t_env *env, int fd)
{
	char *key;
	char *value;
	int	i;
	int flag;

	if (argc == 1)	//export만 들어온 경우
	{
		builtin_export_only(argc, argv, env, fd);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		ft_get_key_value(argv[i], &key, &value);
		if (is_invalid_id(argv[i], key, value))
		{
			printf("minishell: export: \`%s\': not a valid identifier\n", argv[i]);
			flag += 1;
		}
		else
		{
			insert_env(env, key, value);
			free(key);
			free(value);
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}
