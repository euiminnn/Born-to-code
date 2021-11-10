/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/26 17:30:34 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"

static int	_builtin_unset(int argc, char **argv, t_env *env)
{
	char	*key;
	char	*value;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		ft_get_key_value(argv[i], &key, &value);
		if (value)
		{
			ft_putstr_fd("minishell: unset: \`", 2);
			ft_putstr_fd(key, 2);
			ft_putstr_fd("=", 2);
			ft_putstr_fd(value, 2);
			ft_putstr_fd("\': not a valid identifier\n", 2);
			flag = 1;
		}
		else
		{
			remove_env(env, key);
			free(key);
		}
		i++;
	}
	return (flag);
}

int	builtin_unset(int argc, char **argv, t_env *env, int fd)
{
	int		flag;

	(void)fd;
	if (argc == 1)
		return (0);
	flag = _builtin_unset(argc, argv, env);
	return (flag);
}
