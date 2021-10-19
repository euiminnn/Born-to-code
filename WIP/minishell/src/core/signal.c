#include "minishell.h"

void	sigint_handler(int sig)
{
	printf("\b\b  \b\b\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_code = 1;
}

void	sigint_handler_in_execute(int sig)
{
	printf("\n");
}

void	sigquit_handler(int sig)
{
	printf("\b\b  \b\b");
}

void	sigquit_handler_in_execute(int sig)
{
	printf("Quit: 3\n");
}
