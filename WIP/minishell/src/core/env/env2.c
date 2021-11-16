/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:49:18 by echung            #+#    #+#             */
/*   Updated: 2021/11/16 17:49:19 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/env/env.h"
#include "lib/libft.h"
#include "utils/utils.h"

#define KEY_MAX 1000000

static t_env	*search_env_before_node(t_env *env, char *key)
{
	t_env		*node;
	t_env		*before_node;
	t_env_data	*data;

	before_node = env;
	node = before_node->next;
	while (node)
	{
		data = node->data;
		if (ft_strncmp(data->key, key, KEY_MAX) >= 0)
			break ;
		before_node = node;
		node = node->next;
	}
	return (before_node);
}

void	insert_env(t_env *env, char *key, char *value)
{
	t_env	*before_node;
	t_env	*new_node;

	new_node = init_list();
	new_node->data = init_env_data(key, value);
	before_node = search_env_before_node(env, key);
	new_node->next = before_node->next;
	before_node->next = new_node;
}

int	remove_env(t_env *env, char *key)
{
	t_env		*before_node;
	t_env		*del_node;
	t_env_data	*del_node_data;

	before_node = search_env_before_node(env, key);
	del_node = before_node->next;
	if (!del_node)
		return (ERROR);
	del_node_data = del_node->data;
	if (ft_strncmp(del_node_data->key, key, KEY_MAX) != 0)
		return (ERROR);
	before_node->next = before_node->next->next;
	free_env_data(del_node_data);
	free(del_node);
	return (OK);
}

void	free_env(t_env *env)
{
	free_list(env, free_env_data);
}

char	**to_string_env(t_env *env, char *(*to_string)(t_env_data *data))
{
	char	*(*real_to_string)(void *data);

	real_to_string = (char *(*)(void *))to_string;
	return (to_string_list(env, real_to_string));
}
