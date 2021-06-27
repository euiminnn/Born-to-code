/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:07:20 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 15:39:33 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	t_node	*curr_top;
	t_node	*new_top;

	curr_top = stack->top;
	new_top = curr_top->prev;
	if (new_top)
		new_top->next = NULL;
	stack->top = new_top;
	stack->size--;
	if (stack->size == 0)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	free(curr_top);
	return (curr_top->data);
}

int	pop_bottom(t_stack *stack)
{
	t_node	*curr_bottom;
	t_node	*new_bottom;

	curr_bottom = stack->bottom;
	new_bottom = curr_bottom->next;
	if (new_bottom)
		new_bottom->prev = NULL;
	stack->bottom = new_bottom;
	stack->size--;
	if (stack->size == 0)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	free(curr_bottom);
	return (curr_bottom->data);
}
