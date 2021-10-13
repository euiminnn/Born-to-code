#include "core/execute/proc.h"
#include "utils/utils.h"
#include <unistd.h>

int get_proc_type(t_proc *proc)
{
	return (P_EXTERN);
}

int execute_builtin_proc(t_proc *proc)
{
	return (OK);
}

static int	wait_cmd()
{
	int	status;

	wait(&status);
	return (OK);
}

// TODO: if PATH not valid
int execute_extern_proc(t_proc *proc)
{
	char	*command;
	char	**envp;
	char	**path;
	int		idx;
	int		pid;
    
	envp = export_env(proc->env);
	pid = fork();
	if (pid > 0)
		wait_cmd();
	else
	{
		ft_dup(proc->fd_in, STDIN_FILENO);
		ft_dup(proc->fd_out, STDOUT_FILENO);
		if (ft_strchr(proc->argv[0], '/'))
			execve(proc->argv[0], proc->argv, envp);
		else 
		{
			idx = -1;
			path = ft_split(search_env(proc->env, "PATH"), ':');
			while (path[++idx])
			{
				command = ft_strjoins((char *[3]){path[idx], "/", proc->argv[0]}, 3);
				execve(command, proc->argv, envp);
				free(command);
			}
		}
	}
	ft_free_strings(envp);
	return (OK);
}

void    free_proc(t_proc *proc)
{
	ft_free_strings(proc->argv);
	free(proc);
}