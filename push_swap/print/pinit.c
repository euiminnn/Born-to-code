/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 02:36:31 by echung            #+#    #+#             */
/*   Updated: 2021/06/29 03:16:05 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_print	*print_init(void)
{
	t_print	*print;

	print = (t_print *)malloc(sizeof(t_print));
	print->top = NULL;
	print->bottom = NULL;
	print->size = 0;
	return (print);
}

t_pnode	*pnode_init(char *op)
{
	t_pnode	*new_pnode;

	new_pnode = (t_pnode *)malloc(sizeof(t_pnode));
	new_pnode->op = op;
	new_pnode->prev = NULL;
	new_pnode->next = NULL;
	return (new_pnode);
}
