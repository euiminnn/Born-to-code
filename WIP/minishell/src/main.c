/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:18:24 by ycha              #+#    #+#             */
/*   Updated: 2021/10/16 02:43:16 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	printf("exit\n");
	free(env);
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	sigint_old = signal(SIGINT, sigint_handler);
	sigquit_old = signal(SIGQUIT, sigquit_handler);
	start(envp);
	return (0);
}
