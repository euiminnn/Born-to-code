/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:54:20 by echung            #+#    #+#             */
/*   Updated: 2021/10/26 17:43:17 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"

static int	move_to_home(char **argv, t_env *env)
{
	int		cd_ret;
	char	*search_ret;

	search_ret = search_env(env, "HOME");
	if (!search_ret)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	cd_ret = chdir(search_ret);
	if (cd_ret == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(search_ret, 2);
		ft_putstr_fd("No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	builtin_cd(int argc, char **argv, t_env *env, int fd)
{
	int		cd_ret;
	char	*search_ret;

	(void)fd;
	if (argc == 1)
		return (move_to_home(argv, env));
	cd_ret = chdir(argv[1]);
	if (cd_ret == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}
