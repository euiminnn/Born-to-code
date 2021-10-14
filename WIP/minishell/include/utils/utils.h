#include "lib/libft.h"

#include "define.h"
#include <stdio.h>
#include <string.h>

void	ft_exit(int err);
char*	ft_strjoins(char **strs, int n);
char    **ft_free_strings(char **arr);
void    ft_free(void *data);
void    ft_close(int fd);
int     ft_dup(int fd1, int fd2);
int     ft_error(int errtype);