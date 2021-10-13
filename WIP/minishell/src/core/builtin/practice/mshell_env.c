/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:32:48 by echung            #+#    #+#             */
/*   Updated: 2021/10/13 16:37:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtin.h"

void mshell_env(int argc, char **argv, char **env)
{
	printf("TERM_PROGRAM=%s\n", getenv("TERM_PROGRAM"));
	printf("TERM=%s\n", getenv("TERM"));
	printf("SHELL=%s\n", getenv("SHELL"));
	printf("TMPDIR=%s\n", getenv("TMPDIR"));
	printf("TERM_PROGRAM_VERSION=%s\n", getenv("TERM_PROGRAM_VERSION"));
	printf("TERM_SESSION_ID=%s\n", getenv("TERM_SESSION_ID"));
	printf("ZSH=%s\n", getenv("ZSH"));
	printf("PATH=%s\n", getenv("PATH"));
	printf("PWD=%s\n", getenv("PWD"));
	printf("HOME=%s\n", getenv("HOME"));
}

int main(int argc, char **argv, char **env)
{
	mshell_env(argc, argv, env);
}
