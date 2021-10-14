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

void	builtin_export_only(int argc, char **argv, t_env *env)
{
	t_env *node;

	node = env->next;
	while (node)
	{
		printf("declare -x ");
		printf("%s", node->key);
		printf("=");
		printf("\"");
		printf("%s", node->value);
		printf("\"\n");
		node = node->next;
	}
}

void	builtin_export(int argc, char **argv, t_env *env)
{
	char **output;

	if (argc == 1)	//export만 들어온 경우
		builtin_export_only(argc, argv, env);
	output = get_key_value(argv[1]);
    insert_env(env, output[0], output[1]);
}
