#include "core/error.h"

void	ft_error_msg_multi_line()
{
	printf("minishell: multi line not allowed\n");
}

void	ft_error_msg_syntax()
{
	printf("minishell: syntax error\n");
}

void	ft_error_msg_no_file(char *file)
{
	printf("minishell: %s: No such file or directory\n", file);
}

void	ft_error_msg_not_command(char *command)
{
    printf("minishell: %s: command not found\n", command);
}
