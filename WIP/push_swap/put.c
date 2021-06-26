/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:06:52 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 06:16:32 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(t_stack *stack, int new_data)

{
	t_node	*new_node;
	t_node	*old_top;

	new_node = node_init(new_data);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		old_top = stack->top;
		old_top->next = new_node;
		new_node->prev = old_top;
		stack->top = new_node;
	}
	stack->size++;
}

void	put_bottom(t_stack *stack, int new_data)

{
	t_node	*new_node;
	t_node	*old_bottom;

	new_node = node_init(new_data);
	if (stack->bottom == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		old_bottom = stack->bottom;
		old_bottom->prev = new_node;
		new_node->next = old_bottom;
		stack->bottom = new_node;
	}
	stack->size++;
}

void	push(t_stack *from, t_stack *to, char ab)
{
	int	popdata;

	if (from->size != 0)
	{
		popdata = pop(from);
		put(to, popdata);
		if (ab)
			printf("p%c\n", ab);
	}
}
