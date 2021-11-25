/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:33:51 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 03:23:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <dirent.h>

#include "minishell.h"
#include "core/signal.h"
#include "core/builtin.h"
#include "core/execute/execute.h"
#include "utils/utils.h"
#include "core/error.h"
#include "debug/debug_execute.h"

static int	_execute_extern_proc(t_proc *proc);
static int	_execute_extern_proc_path(t_proc *proc);
static void	wait_process(t_proc *proc);

void	execute_builtin_proc(t_proc *pc)
{
	int	type;
	int	(*builtin[10])();

	builtin[P_BUILTIN_CD] = builtin_cd;
	builtin[P_BUILTIN_ECHO] = builtin_echo;
	builtin[P_BUILTIN_ENV] = builtin_env;
	builtin[P_BUILTIN_EXIT] = builtin_exit;
	builtin[P_BUILTIN_EXPORT] = builtin_export;
	builtin[P_BUILTIN_PWD] = builtin_pwd;
	builtin[P_BUILTIN_UNSET] = builtin_unset;
	type = get_proc_type(pc);
	DEBUG && printf("-------builtin------\n");
	DEBUG && print_proc_type(type);
	g_exit_code = builtin[type](pc->argc, pc->argv, pc->env, pc->fd_out);
}

/**
 * 원래 프로세스에 문제가 없도록
 * 시그널을 원래 시그널로 되돌려놓는다
 * dup 으로 fd 를 연결하고,
 * 외부 프로그램을 실행시킨다.
 */

void	execute_extern_proc(t_proc *proc)
{
	if (fork() == 0)
	{
		signal(SIGINT, sig_handler()->sigint);
		signal(SIGQUIT, sig_handler()->sigquit);
		ft_dup(proc->fd_in, STDIN_FILENO);
		ft_dup(proc->fd_out, STDOUT_FILENO);
		exit(_execute_extern_proc(proc));
	}
	wait_process(proc);
}

static int	_execute_extern_proc(t_proc *proc)
{
	char	**envp;
	char	*command;
	char	**path;
	int		idx;

	if (proc->argc == 0)
		exit(0);
	if (ft_strchr(proc->argv[0], '/'))
		return (_execute_extern_proc_path(proc));
	idx = -1;
	path = ft_split(search_env(proc->env, "PATH"), ':');
	envp = to_string_env(proc->env, to_string_env_data);
	while (path && path[++idx])
	{
		command = ft_strjoins((char *[3]) \
		{path[idx], "/", proc->argv[0]}, 3);
		execve(command, proc->argv, envp);
		free(command);
	}
	free(envp);
	return (ERR_EXECTUE_COMMAND_NOT_FOUND);
}

static int	_execute_extern_proc_path(t_proc *proc)
{
	char	**envp;
	DIR		*dirp;

	dirp = opendir(proc->argv[0]);
	if (dirp)
	{
		closedir(dirp);
		return (ERR_EXECTUE_COMMAND_IS_DIRECTORY);
	}
	envp = to_string_env(proc->env, to_string_env_data);
	execve(proc->argv[0], proc->argv, envp);
	free(envp);
	return (ERR_EXECTUE_COMMAND_NO_FILE);
}

static void	wait_process(t_proc *proc)
{
	int	status;

	wait(&status);
	g_exit_code = WEXITSTATUS(status);
	if (g_exit_code == ERR_EXECTUE_COMMAND_IS_DIRECTORY \
		|| g_exit_code == ERR_EXECTUE_COMMAND_NOT_FOUND \
		|| g_exit_code == ERR_EXECTUE_COMMAND_NO_FILE)
		ft_error(g_exit_code, proc->argv[0]);
	if (WIFSIGNALED(status))
		g_exit_code = 128 + WTERMSIG(status);
}
