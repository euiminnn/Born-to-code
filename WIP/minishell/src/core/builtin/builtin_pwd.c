/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/11 02:55:55 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "core/builtin.h"

#define PATH_MAX 1000

int	builtin_pwd(int argc, char **argv, t_env *env, int fd)
{
	char cwd[PATH_MAX];

	(void)env;
	(void)argc;
	(void)argv;
   	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putstr_fd(cwd, fd);
		ft_putstr_fd("\n", fd);
	}
	return (0);
}

