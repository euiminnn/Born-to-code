/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:54:20 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 03:18:05 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#define PATH_MAX 1000

static int	move_to_home(char **argv, t_env *env)
{
	int		cd_ret;
	char	*search_ret;
	char	cwd[PATH_MAX];

	search_ret = search_env(env, "HOME");
	if (!search_ret)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env(env, "OLDPWD", cwd);
	cd_ret = chdir(search_ret);
	if (cd_ret == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(search_ret, 2);
		ft_putstr_fd("No such file or directory\n", 2);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env(env, "PWD", cwd);
	return (0);
}

int	builtin_cd(int argc, char **argv, t_env *env, int fd)
{
	int		cd_ret;
	char	*search_ret;
	char	cwd[PATH_MAX];

	(void)fd;
	if (argc == 1)
		return (move_to_home(argv, env));
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env(env, "OLDPWD", cwd);
	cd_ret = chdir(argv[1]);
	if (cd_ret == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env(env, "PWD", cwd);
	return (0);
}
