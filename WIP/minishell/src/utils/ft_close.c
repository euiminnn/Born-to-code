#include "utils/utils.h"

void    ft_close(int fd)
{
    if (fd == STDIN_FILENO)
        return ;
    if (fd == STDOUT_FILENO)
        return ;
    if (fd == STDERR_FILENO)
        return ;
    close(fd);
}