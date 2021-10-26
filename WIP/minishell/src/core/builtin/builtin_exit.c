/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/26 17:16:05 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"

int	is_num(char *str)
{
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			str++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	builtin_exit(int argc, char **argv, t_env *env, int fd)
{
	(void)env;
	ft_putstr_fd("exit\n", fd);
	if (argc == 1)
		exit(g_exit_code);
	if (argc > 1)
	{
		if (is_num(argv[1]) == TRUE)
		{
			if (argc == 2)
				exit(ft_atoi(argv[1]));
			printf("minishell: exit: too many arguments\n");
			return (1);
		}
		else
		{
			printf("minishell: exit: %s: numeric argument required\n", argv[1]);
			exit(255);
		}
	}
	return (0);
}
