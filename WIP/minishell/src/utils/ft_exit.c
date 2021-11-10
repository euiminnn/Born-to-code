#include "utils/utils.h"

void	ft_exit(int err)
{
	ft_putstr_fd(strerror(err), 2);
	ft_putstr_fd("\n", 2);
	exit(err);
}
