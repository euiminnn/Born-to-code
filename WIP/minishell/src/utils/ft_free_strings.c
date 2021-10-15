#include "utils/utils.h"

char    **ft_free_strings(char **arr)
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
	return (0);
}