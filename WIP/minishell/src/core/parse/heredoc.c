#include "utils/utils.h"
#include "core/env/env.h"
#include "core/parse/parse.h"
#include "debug/debug_parse.h"
#include "debug/debug_utils.h"
#include "minishell.h"

#define PIPE_IN 1
#define PIPE_OUT 0
#define LIMITER_MAX 420000

static int input_heredoc(char *limiter);

/**
 * 토큰을 돌면서,
 * T_LEFT_DOUBLE_REDIR 인 경우에는
 * fd 값을 받아오고, 문자열로 저장한다.
 */

void  heredoc(t_list *tokens)
{
    int     fd;
    t_list  *node;
    t_token *token;

    node = tokens->next;
    while (node)
    {
        token = node->data;
        node = node->next;
        if (token->type == T_LEFT_DOUBLE_REDIR)
        {
            fd = input_heredoc(token->value);
            free(token->value);
            token->value = ft_itoa(fd);
        }
    }
}

/**
 * 파이프를 하나 만들어서 입력을 받고,
 * 출력 fd 를 반환한다.
 */

static int input_heredoc(char *limiter)
{
    int pipe_fd[2];
    char    *line;

    pipe(pipe_fd);
    while (1)
    {
        line = readline("> ");
        if (!line)
            break;
        if (ft_strncmp(line, limiter, LIMITER_MAX) == 0)
            break;
        write(pipe_fd[PIPE_IN], line, ft_strlen(line));
        write(pipe_fd[PIPE_IN], "\n", 1);
    }
    close(pipe_fd[PIPE_IN]);
    return (pipe_fd[PIPE_OUT]);
}
