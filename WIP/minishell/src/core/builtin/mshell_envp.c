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

#include "../../../include/builtin.h"

void	mshell_envp(int argc, char **argv, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		printf("\n%s", env[i]);
		i++;
	}
/*
	for (i = 0; env[i] != NULL; i++)
		printf("\n%s", env[i]);
*/
}

int	main(int argc, char **argv, char **env)
{
	mshell_envp(argc, argv, env);
	return (0);
}
