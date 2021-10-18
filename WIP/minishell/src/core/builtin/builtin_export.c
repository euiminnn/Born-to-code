/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/14 17:16:37 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"

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

void	builtin_export_only(int argc, char **argv, t_env *env, int fd)
{
	t_env *node;

	node = env->next;
	while (node)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(node->key, fd);
		ft_putstr_fd("=", fd);
		ft_putstr_fd("\"", fd);
		ft_putstr_fd(node->value, fd);
		ft_putstr_fd("\"\n", fd);
		node = node->next;
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
