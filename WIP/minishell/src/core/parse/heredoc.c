#include "utils/utils.h"
#include "core/env.h"
#include "core/parse/parse.h"
#include "debug/debug_parse.h"
#include "debug/debug_utils.h"
#include "minishell.h"

#define PIPE_IN 1
#define PIPE_OUT 0
#define LIMITER_MAX 420000

static int read_heredoc(char *limiter)
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
            fd = read_heredoc(token->value);
            free(token->value);
            token->value = ft_itoa(fd);
        }
    }
}
