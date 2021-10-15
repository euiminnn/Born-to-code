/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/14 17:19:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"

int	builtin_unset(int argc, char **argv, t_env *env, int fd)
{
	char **output;

	(void)fd;
	if (argc == 1)	//export만 들어온 경우
		return (1);
	output = get_key_value(argv[1]);
    remove_env(env, output[0]);
	return (0);
}
