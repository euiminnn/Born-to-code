#include "minishell.h"

typedef struct s_list t_list;

typedef struct s_argv
{
	t_list *list;
}   t_argv;

void    init_list(char **envp)
{

}

t_argv  *envp_to_list(char **envp)
{
	init_list(&argv);
}

void    startshell(char **envp)
{
	envp_to_list(envp);
	while (1)
	{
		write_message_to_command("bash > ");
		get_command();
		parse_command();
	}
}    

int main(int argc, char **argv, char **envp)
{
	startshell();
	return (0);
}