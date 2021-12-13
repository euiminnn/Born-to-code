/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:54:20 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 20:42:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/error.h"
#include <fcntl.h>
#define PATH_MAX 1000

static int	move_to_home(char **argv, t_env *env)
{
	int		cd_ret;
	char	*search_ret;
	char	cwd[PATH_MAX];

	(void)argv;
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

/*
int	builtin_cd(int argc, char **argv, t_env *env, int fd)
{
	int		cd_ret;
	char	cwd[PATH_MAX];
	DIR		*dirp;

	(void)fd;
	if (argc == 1)
		return (move_to_home(argv, env));
	dirp = opendir(proc->argv[0]);
	if (!dirp)
	{
		error_message_for_cd_
		return (1);
	}
	closedir(dirp);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env(env, "OLDPWD", cwd);
	cd_ret = chdir(argv[1]);
	if (cd_ret == -1)
	{
		error_message_for_cd(argv[1]);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		replace_env(env, "PWD", cwd);
	return (0);
}
*/

int	builtin_cd(int argc, char **argv, t_env *env, int fd)
{
	int		fd_argv;
	int		cd_ret;
	char	cwd[PATH_MAX];

	(void)fd;
	if (argc == 1)
		return (move_to_home(argv, env));
	getcwd(cwd, sizeof(cwd));
	cd_ret = chdir(argv[1]);
	if (cd_ret == -1)
	{
		fd_argv = open(argv[1], O_RDONLY);
		if (fd_argv > 0)
		{
			close(fd_argv);
			error_message_for_cd_is_file(argv[1]);
			return (1);
		}
		error_message_for_cd_not_exist(argv[1]);
		return (1);
	}
	replace_env(env, "OLDPWD", cwd);
	getcwd(cwd, sizeof(cwd));
	replace_env(env, "PWD", cwd);
	return (0);
}
