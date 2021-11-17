/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:43:18 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:43:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "core/signal.h"
#include "core/env/env.h"
#include "core/parse/parse.h"
#include "debug/debug_parse.h"
#include "debug/debug_utils.h"
#include "minishell.h"

#define PIPE_IN 1
#define PIPE_OUT 0
#define LIMITER_MAX 420000

#define ERR_SIGNAL  1

static int	input_heredoc(char *limiter);
static void	sigint_handler_in_heredoc(int sig);

/**
 * 토큰을 돌면서,
 * T_LEFT_DOUBLE_REDIR 인 경우에는
 * fd 값을 받아오고, 문자열로 저장한다.
 */

int	heredoc(t_list *tokens)
{
	int		fd;
	t_list	*node;
	t_token	*token;

	node = tokens->next;
	while (node)
	{
		token = node->data;
		node = node->next;
		if (token->type == T_LEFT_DOUBLE_REDIR)
		{
			fd = input_heredoc(token->value);
			if (fd == -1)
				return (ERROR);
			free(token->value);
			token->value = ft_itoa(fd);
		}
	}
	return (OK);
}

/**
 * 파이프를 하나 만들어서 입력을 받고,
 * 출력 fd 를 반환한다.
 * 
 * 시그널 처리를 위해서 fork 를 하고,
 * 실제로 시그널을 받은경우는 -1을 반환합니다.
 */

static int	input_heredoc(char *limiter)
{
	int		status;
	int		pipe_fd[2];
	char	*line;

	pipe(pipe_fd);
	signal(SIGINT, SIG_IGN);
	if (fork() == 0)
	{
		ft_close(pipe_fd[PIPE_OUT]);
		signal(SIGINT, sigint_handler_in_heredoc);
		while (1)
		{
			line = readline("> ");
			if (!line || ft_strncmp(line, limiter, LIMITER_MAX) == 0)
				exit(0);
			write(pipe_fd[PIPE_IN], line, ft_strlen(line));
			write(pipe_fd[PIPE_IN], "\n", 1);
		}
	}
	ft_close(pipe_fd[PIPE_IN]);
	wait(&status);
	signal(SIGINT, sigint_handler);
	if (WEXITSTATUS(status) == ERR_SIGNAL)
		return (-1);
	return (pipe_fd[PIPE_OUT]);
}

/**
 * SIGINT 에 대해서 자식 프로레스가 처리되는 동안의 시그널을 처리합니다.
 *
 * @details ^C 를 지우고 exit 1 합니다.
 *
 * @param sig 시그널
 */
static void	sigint_handler_in_heredoc(int sig)
{
	printf("\b\b  \b\b\n");
	exit(ERR_SIGNAL);
}
