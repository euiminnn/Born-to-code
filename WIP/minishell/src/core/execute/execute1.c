#include "core/env.h"
#include "minishell.h"
#include "core/execute/execute.h"
#include "core/execute/proc.h"
#include "core/parse/cmd.h"
#include "utils/utils.h"
#include "debug/debug_execute.h"

#define PIPE_IN 1
#define PIPE_OUT 0

static void	wait_cmds();

/**
 * 커맨드로 프로세스를 만들기
 * 프로세스 종류에 따라서,
 *     빌트인으로 실행
 *     외부 명령어로 실행
 */

void	execute_cmd(t_cmd *cmd, t_env *env, int fd_in, int fd_out)
{
	t_proc *proc;

	proc = build_proc(cmd, env, fd_in, fd_out);
	if (!proc)
		return ;
	DEBUG && printf("-----process-----\n");
	DEBUG && print_proc(proc, 0);
	if (get_proc_type(proc) == P_EXTERN)
		execute_extern_proc(proc);
	else
		execute_builtin_proc(proc);
	free_proc(proc);
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
 *     fd_in 이랑 fd_out 은 필요없음!
 *     그래서 둘다 닫음!
 * 	   자식 기다리기
 * 자식
 *     pipe_fd[OUT] 은 필요없음!
 *     그래서 닫음!
 *     exit code 로 종료하기
 */

/**
 * 자식 프로세스의 시그널과 동시에
 * 부모 프로세스의 시그널이 작동되지 않게 하기 위해서
 * 부모 프로세스의 시그널는 끕니다.
 */

void	execute_cmds(t_list *node, t_env *env, int fd_in, int last_pid)
{
	int		pipe_fd[2];
	int		fd_out;
	int		pid;

	if (!node)
	{
		wait_cmds(last_pid);
		return ;	
	}
	fd_out = STDOUT_FILENO;
	if (node->next)
	{
		pipe(pipe_fd);
		fd_out = pipe_fd[PIPE_IN];
	}
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		ft_close(pipe_fd[PIPE_OUT]);
		execute_cmd(node->data, env, fd_in, fd_out);
		exit(g_exit_code);
	}
	ft_close(fd_in);
	ft_close(fd_out);
	execute_cmds(node->next, env, pipe_fd[PIPE_OUT], pid);
}

static void	wait_cmds(int last_pid)
{
	int	status;

	waitpid(last_pid, &status, 0);
	g_exit_code = WEXITSTATUS(status);
	while (wait(&status) != -1)
		;
}

/**
 * 시그널 처리 방식을 바꿔주고,
 * 
 * 명령어 2개 이상이면, fork 뜨면서 재귀,
 * 1개면 그냥 실행
 * 
 * 실행이 끝났으면, 시그널 원래 처리 방식으로 복귀
 */

void	execute(t_list *cmds, t_env *env)
{
	int count;

	signal(SIGINT, sigint_handler_in_execute);
	signal(SIGQUIT, sigquit_handler_in_execute);
	count = count_list(cmds);
	if (count == 1)
		execute_cmd(cmds->next->data, env, STDIN_FILENO, STDOUT_FILENO);
	else if (count > 1)
		execute_cmds(cmds->next, env, STDIN_FILENO, -1);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
