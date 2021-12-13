/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:18:24 by ycha              #+#    #+#             */
/*   Updated: 2021/11/26 04:08:37 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start(t_env *env, char *line)
{
	t_list	*cmds;

	cmds = init_list();
	if (parse(line, env, cmds))
		execute(cmds, env);
	free_list(cmds, free_cmd);
}

void	loop(t_env *env)
{
	char	*line;

	while (input(&line))
	{
		start(env, line);
		free(line);
	}
	printf("exit\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = init_env(envp);
	termios_echoctl_off();
	sig_handler()->sigint = signal(SIGINT, sigint_handler);
	sig_handler()->sigquit = signal(SIGQUIT, sigquit_handler);
	if (argc == 3 && ft_strncmp(argv[1], "-c", 3) == 0)
	{
		start(env, argv[2]);
		exit(g_exit_code);
	}
	loop(env);
	free_env(env);
	return (0);
}
