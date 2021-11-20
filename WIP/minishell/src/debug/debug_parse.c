/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:21:25 by ycha              #+#    #+#             */
/*   Updated: 2021/11/20 22:21:26 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug/debug_parse.h"
#include "debug/debug_utils.h"

int	print_cmd(t_cmd *cmd, int depth)
{
	print_space(depth);
	printf("{\n");
	print_space(depth + 1);
	printf("args : \n");
	print_token_list(cmd->args, depth + 2);
	print_space(depth + 1);
	printf("rd : \n");
	print_token_list(cmd->rd, depth + 2);
	print_space(depth);
	printf("}\n");
	return (OK);
}

int	print_cmd_list(t_list *cmds, int depth)
{
	t_list	*node;

	node = cmds->next;
	print_space(depth);
	printf("[\n");
	while (node)
	{
		print_cmd(node->data, depth + 1);
		node = node->next;
	}
	print_space(depth);
	printf("]\n");
	return (OK);
}

int	print_token(t_token *token, int depth)
{
	char	*c;

	if (token->type == T_ARG)
		c = "T_ARG";
	else if (token->type == T_LEFT_REDIR)
		c = "T_LEFT_REDIR";
	else if (token->type == T_RIGHT_REDIR)
		c = "T_RIGHT_REDIR";
	else if (token->type == T_LEFT_DOUBLE_REDIR)
		c = "T_LEFT_DOUBLE_REDIR";
	else if (token->type == T_RIGHT_DOUBLE_REDIR)
		c = "T_RIGHT_DOUBLE_REDIR";
	else
		c = "T_PIPE";
	print_space(depth);
	printf("{type: %s, value: %s}\n", c, token->value);
	return (OK);
}

int	print_token_list(t_list *tokens, int depth)
{
	t_list	*node;

	node = tokens->next;
	print_space(depth);
	printf("[\n");
	while (node)
	{
		print_token(node->data, depth + 1);
		node = node->next;
	}
	print_space(depth);
	printf("]\n");
	return (OK);
}
