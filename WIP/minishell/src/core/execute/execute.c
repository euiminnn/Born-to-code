#include "core/env.h"
#include "core/execute/execute.h"
#include "core/execute/proc.h"
#include "core/parse/cmd.h"
#include "utils/utils.h"
#include "debug/debug_execute.h"

#define PIPE_IN 1
#define PIPE_OUT 0

int execute_cmd(t_cmd *cmd, t_env *env, int fd_in, int fd_out)
{
	t_proc *proc;

	proc = build_proc(cmd, env, fd_in, fd_out);
	print_proc(proc, 0);
	if (get_proc_type(proc) == P_EXTERN)
		execute_extern_proc(proc);
	else
		execute_builtin_proc(proc);
	free_proc(proc);
	return (OK);
}

int	wait_cmd()
{
	int	status;

	wait(&status);
	return (OK);
}

/**
 * 명령어들을 재귀를 돌면서 호출
 * 
 * fd_in 은 앞의 명령어에서의 fd_out 입니다.
 * 파이프를 만들어요.
 * pipe_fd[IN], pipe_fd[OUT] 이 나옴!
 * <fd_in> 명령어1 <fd_out=pipe_fd[PIPE_IN]> | <pipe_fd[PIPE_OUT]> 명령어2 <...>
 * fork 를 해요
 * 부모
 * 		fd_in 이랑 fd_out 은 필요없음!
 * 		그래서 둘다 닫음!
 * 자식
 * 		pipe_fd[OUT] 은 필요없음!
 * 		그래서 닫음!
 */
int execute_cmds(t_list *node, t_env *env, int fd_in)
{
	int		pipe_fd[2];
	int		fd_out;
	int		pid;

	if (!node)
		return (OK);
	fd_out = STDOUT_FILENO;
	if (node->next)
	{
		pipe(pipe_fd);
		fd_out = pipe_fd[PIPE_IN];
	}
	pid = fork();
	if (pid > 0)
	{
		ft_close(fd_in);
		ft_close(fd_out);
		wait_cmd();
	}
	else
	{
		ft_close(pipe_fd[PIPE_OUT]);
		execute_cmd(node->data, env, fd_in, fd_out);
		exit(0);
	}
	execute_cmds(node->next, env, pipe_fd[PIPE_OUT]);
	return (OK);
}

int execute(t_list *cmds, t_env *env)
{
	int count;

	count = count_list(cmds);
	if (count == 1)
		execute_cmd(cmds->next->data, env, STDIN_FILENO, STDOUT_FILENO);
	else if (count > 1)
		execute_cmds(cmds->next, env, STDIN_FILENO);
	return (OK);
}
