/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:43:28 by echung            #+#    #+#             */
/*   Updated: 2021/10/26 17:43:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#define PATH_MAX 1000

int	builtin_pwd(int argc, char **argv, t_env *env, int fd)
{
	char	cwd[PATH_MAX];

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
