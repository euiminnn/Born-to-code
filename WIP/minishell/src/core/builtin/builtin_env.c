/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:40 by echung            #+#    #+#             */
/*   Updated: 2021/10/23 17:59:24 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"

static char	*to_string(t_env_data *data)
{
	if (!data->value)
		return (NULL);
	return (ft_strjoins((char *[4]){data->key, "=", data->value, "\n"}, 4));
}

void	builtin_env_only(int argc, char **argv, t_env *env, int fd)
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

int	builtin_env(int argc, char **argv, t_env *env, int fd)
{
	char *key;
	char *value;
	int	i;

	if (argc == 1)	//env만 들어온 경우
	{
		builtin_env_only(argc, argv, env, fd);
		return (0);
	}
	else if (argc > 1)
	{
		ft_get_key_value(argv[1], &key, &value);
		if (!value)
		{
			printf("env: %s: No such file or directory\n", key);
			return (127);
		}
		free(key);
		free(value);
		builtin_env_only(argc, argv, env, fd);
		i = 1;
		while (argv[i])
		{
			ft_putstr_fd(argv[i], fd);
			ft_putstr_fd("\n", fd);
			i++;
		}
		return (0);
	}
	return (0);

}
