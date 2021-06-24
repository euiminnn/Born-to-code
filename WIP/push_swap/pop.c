/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:07:20 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 23:05:19 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    pop(t_stack *stack)
{
    t_node *curr_top;
    t_node *new_top;

    curr_top = stack->top;
    if (curr_top == NULL)
	{
        printf("error\n");
		return (-1);
	}
    else
    {
        new_top = curr_top->prev;
		/* HERE, 데이터가 1개인 경우 */
        if (new_top)
			new_top->next = NULL;		//size 1개일 때 pop하면 stack->top = NULL 됨
        stack->top = new_top;
    }
    stack->size--;

	if (stack->size == 0)
	{
		stack->top = NULL;		//norm 줄 수 넘으면 빼기
		stack->bottom = NULL;
	}
    free(curr_top);
	return(curr_top->data);
}

int    pop_bottom(t_stack *stack)
{
    t_node *curr_bottom;
    t_node *new_bottom;

    curr_bottom = stack->bottom;

    if (curr_bottom == NULL)
        return (-1);
    else
    {
        new_bottom = curr_bottom->next;
        if (new_bottom)
			new_bottom->prev = NULL;
        stack->bottom = new_bottom;
    }
    stack->size--;

	if (stack->size == 0)
	{
		stack->top = NULL;
		stack->bottom = NULL;		//norm 줄 수 넘으면 빼기
	}

    free(curr_bottom);
	return(curr_bottom->data);
}
