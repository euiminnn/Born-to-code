#include "get_next_line.h"
int	get_next_line(char **line)
{
	int	index = 0;
	int	ret;

	*line = malloc(999999999);
	while ((ret = read(0, (*line) + (index), 1)) > 0)
	{
		if ((*line)[index] == '\n' && ((*line)[index + 1] = '\0'))
			return (1);
		index++;
	}
	if (ret == -1)
		return (-1);
	else
		return (0);
	//return (ret == -1) ? -1 : 0;
}
