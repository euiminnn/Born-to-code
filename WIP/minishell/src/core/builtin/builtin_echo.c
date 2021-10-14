/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:19 by echung            #+#    #+#             */
/*   Updated: 2021/10/14 17:12:10 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"

void	builtin_echo(int argc, char **argv, t_env *env)
{
	(void)argc;
	(void)argv;
	(void)env;
	
	if (ft_strncmp(argv[1], "-n", 2))
		printf("Option -n is missing.\n");
	printf("%s", argv[2]); //echo가 argv[0], -n이 argv[1], string이 argv[2] 맞는지
}
