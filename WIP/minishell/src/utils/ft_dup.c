#include "utils/utils.h"
#include <unistd.h>

int	ft_dup(int fd1, int fd2)
{
	int	rt;

	if (fd1 == fd2)
		return (OK);
	rt = dup2(fd1, fd2);
	ft_close(fd1);
	return (rt);
}
