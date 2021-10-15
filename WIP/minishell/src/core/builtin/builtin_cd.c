/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:23:34 by echung            #+#    #+#             */
/*   Updated: 2021/10/14 21:44:23 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include <stdio.h>

int	builtin_cd(int argc, char **argv, t_env *env, int fd)
{
	(void)env;
	(void)argc;
	if (argc == 1)
		ft_putstr_fd("You need a path!\n", fd);
	chdir(argv[1]);
	return (0);
}
