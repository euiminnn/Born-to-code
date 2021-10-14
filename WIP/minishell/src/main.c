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

void    start(char **envp)
{
	char	*line;
	t_env	*env;
	t_list	*cmds;

	env = init_env(envp);
	while (input(&line) == OK)
	{
		cmds = init_list();
		if (parse(line, env, cmds) != OK)
		{
			printf("에러남 ㅠ \n");
			free(line);
			continue ;
		}
		if (execute(cmds, env) != OK)
		{
			printf("에러남 ㅠ \n");
			free(line);
			free_list(cmds, free_cmd);
			continue ;
		}
		free(line);
		free_list(cmds, free_cmd);
	}
	free(env);
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	start(envp);
	return (0);
}
