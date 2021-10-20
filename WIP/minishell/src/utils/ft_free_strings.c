#include "utils/utils.h"

void	ft_free_strings(char **arr)
{
    int idx;

	idx = -1;
	while (arr[++idx])
	{
		free(arr[idx]);
		arr[idx] = 0;
	}
	free(arr);
	arr = 0;
}
