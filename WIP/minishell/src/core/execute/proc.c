#include "core/execute/proc.h"
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

int execute_extern_proc(t_proc *proc)
{
	char	*command;
	char	**envp;
	char	**path;
	int		idx;
	int		pid;
    
	envp = export_env(proc->env);
	path = ft_split(search_env(proc->env, "PATH"), ':');
	pid = fork();
	if (pid > 0)
	{
		wait_cmd();
	}
	else
	{
		if (ft_strchr(proc->argv[0], '/'))
			execve(proc->argv[0], proc->argv, envp);
		else 
		{
			idx = -1;
			while (path[++idx])
			{
				command = ft_strjoins((char *[3]){path[idx], "/", proc->argv[0]}, 3);
				execve(command, proc->argv, envp);
				free(command);
			}
		}
	}
	ft_split_free(envp);
	ft_split_free(path);
	return (OK);
}

void    free_proc(t_proc *proc)
{
	ft_split_free(proc->argv);
	free(proc);
}