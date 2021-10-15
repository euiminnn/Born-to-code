#include "minishell.h"

void	sigint_handler(int sig)
{
	errno = 130;
	printf("\b\b  \b\b\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigquit_handler(int sig)
{
	printf("\b\b  \b\b");
	return ;
}
