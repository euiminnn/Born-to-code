#include "core/execute/redir.h"
#include "lib/libft.h"

#define PIPE_IN 1
#define PIPE_OUT 0
#define LIMITER_MAX 420000

int left_redir(char *file)
{
    return (open(file, O_RDONLY));
}

int left_double_redir(char *limiter)
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

int right_redir(char *file)
{
    return (open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644));
}

int right_double_redir(char *file)
{
    return (open(file, O_WRONLY | O_APPEND | O_CREAT, 0644));
}