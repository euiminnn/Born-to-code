#include "minishell.h"

// #define ERRORCODE = 1 2 4 8

// void free()
// {
// 	(ERRCODE & 2) && free(line);
// 	(ERRCODE & 4) && free(line);
// 	(ERRCODE & 6) && free(line);
// 	(ERRCODE & 2) && free(line);
// }
// ERROCODE |= parse();
// (ERROCODE & 0) |= parse();
// (ERROCODE & 0) |= parse();
// (ERROCODE & 0) |= parse();
// checkerrror(ERRORC);

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
