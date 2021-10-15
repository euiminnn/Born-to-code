#include "minishell.h"

/**
 * 쉘을 입력 받습니다.
 *
 * @param line 입력받은 문자열 저장할 주소
 * @return 성공하면 OK 실패하면 ERROR
 */
static int	input(char **line)
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
	while (input(&line))
	{
		cmds = init_list();
		if (parse(line, env, cmds))
			execute(cmds, env);
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
