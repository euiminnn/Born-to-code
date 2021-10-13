#include "minishell.h"

int	input(char **line)
{
    char *str;

	str = readline("의민쉘$ ");
	if (str)
		*line = str;
	else
		return (ERROR);
	add_history(str);
    return(OK);
}