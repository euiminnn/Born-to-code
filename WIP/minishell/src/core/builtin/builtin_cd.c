/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:23:34 by echung            #+#    #+#             */
/*   Updated: 2021/10/14 17:24:27 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"

void	builtin_cd(int argc, char **argv, char **env)
{
	(void)env;
	(void)argc;
	if (argc == 1)
		printf("You need a path!\n")
	chdir(argv[1]);
}
