/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pput.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 02:50:21 by echung            #+#    #+#             */
/*   Updated: 2021/06/29 02:52:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pput(t_print *print, char *op)
{
	t_pnode	*new_pnode;
	t_pnode	*old_top;

	new_pnode = pnode_init(op);
	if (print->top == NULL)
	{
		print->top = new_pnode;
		print->bottom = new_pnode;
	}
	else
	{
		old_top = print->top;
		old_top->next = new_pnode;
		new_pnode->prev = old_top;
		print->top = new_pnode;
	}
	print->size++;
}
