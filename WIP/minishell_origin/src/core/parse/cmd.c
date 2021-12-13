/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:43:08 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:43:09 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse/cmd.h"
#include "core/parse/token.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		exit(12);
	cmd->args = init_list();
	cmd->rd = init_list();
	return (cmd);
}

void	free_cmd(void *data)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)data;
	free_list(cmd->args, free_token);
	free_list(cmd->rd, free_token);
	free(cmd);
}
