/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:40 by echung            #+#    #+#             */
/*   Updated: 2021/10/13 16:42:25 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"

int	builtin_env(int argc, char **argv, t_env *env, int fd)
{
	char	**envp;
	int i;

	i = 0;
	envp = export_env(env);
	while (envp[i])
	{
		ft_putstr_fd(envp[i], fd);
		i++;
	}
/*
	for (i = 0; env[i] != NULL; i++)
		printf("\n%s", env[i]);
*/
	return (0);
}
