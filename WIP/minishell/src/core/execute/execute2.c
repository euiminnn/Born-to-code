#include <unistd.h>

#include "core/builtin.h"
#include "core/execute/execute.h"
#include "utils/utils.h"
#include "core/error.h"
#include "debug/debug_utils.h"

static void	wait_process();

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
	errno = builtin[type](proc->argc, proc->argv, proc->env, proc->fd_out);
}

void	execute_extern_proc(t_proc *proc)
{
	char	*command;
	char	**envp;
	char	**path;
	int		idx;
	int		pid;

	envp = export_env(proc->env);
	pid = fork();
	if (pid == 0)
	{
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
		ft_error(ERR_EXECTUE_NOT_COMMAND, proc->argv[0]);
		exit(errno);
	}
	wait_process();
	ft_free_strings(envp);
}

static void	wait_process()
{
	int	status;

	wait(&status);
	errno = status >> 8;
}
