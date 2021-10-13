#include "utils/utils.h"

char*	ft_strjoins(char **strs, int n)
{
	char	*temp;
	char	*output;
	int		idx;

	idx = 0;
	output = ft_strdup(strs[idx]);
	while (++idx < n)
	{
		temp = ft_strdup(output);
		free(output);
		output = ft_strjoin(temp, strs[idx]);
		free(temp);
	}
	return (output);
}