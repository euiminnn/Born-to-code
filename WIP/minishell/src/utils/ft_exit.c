#include "utils/utils.h"

void	ft_exit(int err)
{
	printf("%s\n", strerror(err));
	exit(err);
}
