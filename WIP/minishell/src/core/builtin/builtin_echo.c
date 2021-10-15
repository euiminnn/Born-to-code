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

int	builtin_echo(int argc, char **argv, t_env *env, int fd)
{
	(void)argc;
	(void)argv;
	(void)env;

	if (ft_strncmp(argv[1], "-n", 2))
	{
		ft_putstr_fd("Option -n is missing.\n", fd);
		return (0);
	}
	ft_putstr_fd(argv[2], fd); //echo가 argv[0], -n이 argv[1], string이 argv[2] 맞는지
	return (0);
}
