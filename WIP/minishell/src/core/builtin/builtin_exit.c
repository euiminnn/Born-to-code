/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 03:16:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/error.h"

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

static int	is_over_the_range(char *str)
{
	long long	num;

	num = 0;
	if ('0' <= *str && *str <= '9' || *str == '+')
	{
		num = ft_atoi(str);
		if (num < 0)
		{
			error_message_for_exit(str);
			return (TRUE);
		}
		else
			return (FALSE);
	}
	else if (*str == '-')
	{
		if (!ft_strncmp(str, "-9223372036854775808", ft_strlen(str)))
			return (FALSE);
		str++;
		return (is_over_the_range(str));
	}
}

int	builtin_exit(int argc, char **argv, t_env *env, int fd)
{
	(void)env;
	ft_putstr_fd("exit\n", 0);
	if (argc == 1)
		exit(g_exit_code);
	if (argc > 1)
	{
		if (is_num(argv[1]) == TRUE)
		{
			if (argc == 2)
			{
				if (is_over_the_range(argv[1]))
					exit(255);
				exit(ft_atoi(argv[1]));
			}
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		else
		{
			error_message_for_exit(argv[1]);
			exit(255);
		}
	}
	return (0);
}
