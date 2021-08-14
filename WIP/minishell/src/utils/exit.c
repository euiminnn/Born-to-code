#include "utils.h"

void	sh_exit(int errno)
{
	printf("%s\n", strerror(errno));
	exit(errno);
}
