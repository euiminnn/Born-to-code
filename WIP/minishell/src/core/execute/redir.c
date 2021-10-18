#include "core/execute/redir.h"
#include "lib/libft.h"

int left_redir(char *file)
{
    return (open(file, O_RDONLY));
}

int left_double_redir(char *fd)
{
    return (ft_atoi(fd));
}

int right_redir(char *file)
{
    return (open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644));
}

int right_double_redir(char *file)
{
    return (open(file, O_WRONLY | O_APPEND | O_CREAT, 0644));
}