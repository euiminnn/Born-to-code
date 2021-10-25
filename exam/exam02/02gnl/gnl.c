#include "get_next_line.h"
int	get_next_line(char **line)
{
	int	index = -1;
	int	ret;

	*line = malloc(999999999);
	while ((ret = read(0, (*line) + (++index), 1)) > 0)
	{
		if ((*line)[index] == '\n' && ((*line)[index + 1] = '\0'))
			return (1);
	}
	return (ret == -1) ? -1 : 0;
}		

