/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:49:09 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 02:03:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/env/env.h"
#include "lib/libft.h"
#include "utils/utils.h"

#define KEY_MAX 1000000

t_env	*init_env(char **envp)
{
	t_env	*ret;
	char	*key;
	char	*value;
	int		idx;
	char	*shlvl;

	ret = init_list();
	idx = -1;
	while (envp[++idx])
	{
		ft_get_key_and_value(envp[idx], &key, &value);
		insert_env(ret, key, value);
		free(key);
		free(value);
	}
	replace_env(ret, "OLDPWD", 0);
	shlvl = ft_itoa(ft_atoi(search_env(ret, "SHLVL")) + 1);
	replace_env(ret, "SHLVL", shlvl);
	free(shlvl);
	return (ret);
}

static t_env	*search_env_node(t_env *env, char *key)
{
	t_env		*node;
	t_env_data	*data;

	node = env->next;
	while (node)
	{
		data = node->data;
		if (ft_strncmp(data->key, key, KEY_MAX) == 0)
			break ;
		node = node->next;
	}
	return (node);
}

char	*search_env(t_env *env, char *key)
{
	t_env		*node;
	t_env_data	*data;

	node = search_env_node(env, key);
	if (!node)
		return (NULL);
	data = node->data;
	return (data->value);
}

void	replace_env(t_env *env, char *key, char *value)
{
	remove_env(env, key);
	insert_env(env, key, value);
}
