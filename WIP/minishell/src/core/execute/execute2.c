#include <unistd.h>

#include "minishell.h"
#include "core/builtin.h"
#include "core/execute/execute.h"
#include "utils/utils.h"
#include "core/error.h"
#include "debug/debug_utils.h"

static void	wait_process(t_proc *proc);

void	execute_builtin_proc(t_proc *proc)
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
	type = get_proc_type(proc);
	DEBUG && printf("-------builtin------\n");
	DEBUG && print_proc_type(type);
	g_exit_code = builtin[type](proc->argc, proc->argv, proc->env, proc->fd_out);
}

/**
 * 원래 프로세스에 문제가 없도록 
 * 시그널을 원래 시그널로 되돌려놓는다
 * dup 으로 fd 를 연결하고,
 * 외부 프로그램을 실행시킨다.
 */

void	execute_extern_proc(t_proc *proc)
{
	char	*command;
	char	**envp;
	char	**path;
	int		idx;

	if (fork() == 0)
	{
		envp = export_env(proc->env);
		signal(SIGINT, sigint_old);
		signal(SIGQUIT, sigquit_old);
		ft_dup(proc->fd_in, STDIN_FILENO);
		ft_dup(proc->fd_out, STDOUT_FILENO);
		if (ft_strchr(proc->argv[0], '/'))
			execve(proc->argv[0], proc->argv, envp);
		else
		{
			idx = -1;
			path = ft_split(search_env(proc->env, "PATH"), ':');
			while (path && path[++idx])
			{
				command = ft_strjoins((char *[3]){path[idx], "/", proc->argv[0]}, 3);
				execve(command, proc->argv, envp);
				free(command);
			}
		}
		exit(ERR_EXECTUE_NOT_COMMAND);
	}
	wait_process(proc);
}

static void	wait_process(t_proc *proc)
{
	int	status;

	wait(&status);
	g_exit_code = WEXITSTATUS(status);
	if (g_exit_code == ERR_EXECTUE_NOT_COMMAND)
		ft_error(ERR_EXECTUE_NOT_COMMAND, proc->argv[0]);
	if (WIFSIGNALED(status))
		g_exit_code = 128 + WTERMSIG(status);
}
