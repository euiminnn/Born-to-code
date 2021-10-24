/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/24 02:08:06 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"

int	builtin_unset(int argc, char **argv, t_env *env, int fd)
{
	char *key;
	char *value;
	int	i;
	int	flag;

	(void)fd;
	if (argc == 1)	//unset만 들어온 경우
		return (0);

	i = 1;
	flag = 0;
	while (argv[i])
	{
		ft_get_key_value(argv[i], &key, &value);
		if (value)
		{
			printf("minishell: unset: \`%s=%s\': not a valid identifier\n", key, value);
			flag += 1;
		}
		else
		{
			remove_env(env, key);
			free(key);
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}
