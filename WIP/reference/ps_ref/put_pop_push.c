/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pop_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:11 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 16:49:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    pop(t_stack *stack)
{
    t_node *curr_top;
    t_node *new_top;

    curr_top = stack->top;
    if (curr_top == NULL)
        return ('e');
    else
    {
        new_top = curr_top->prev;
		/* HERE, 데이터가 1개인 경우 */
        if (new_top)
			new_top->next = NULL;
        stack->top = new_top;
    }
    stack->size--;
    free(curr_top);
	return(curr_top->data);
}
int    pop_bottom(t_stack *stack)
{
    t_node *curr_bottom;
    t_node *new_bottom;

    curr_bottom = stack->bottom;

    if (curr_bottom == NULL)
        return ('e');
    else
    {
        new_bottom = curr_bottom->next;
        if (new_bottom)
			new_bottom->prev = NULL;
        stack->bottom = new_bottom;
    }
    stack->size--;
    free(curr_bottom);
	return(curr_bottom->data);
}

void	put(t_stack *stack, int new_data)

{
	t_node	*new_node;
	t_node	*old_top;

	new_node = node_init(new_data);

	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		return ;
	}
	else
	{
		old_top = stack->top;
		old_top->next= new_node;
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

	old_bottom = stack->bottom;
	old_bottom->prev= new_node;
	new_node->next = old_bottom;
	stack->bottom = new_node;
	stack->size++;
}

void    push(t_stack *from, t_stack *to)
{
	int		popdata;

	popdata = pop(from);
	put(to, popdata);
	printf("pa\n");
}

void	rotate(t_stack *stack)
{
	int		popped;

	popped = pop(stack);
	put_bottom(stack, popped);
	printf("ra\n");
}

void	rrotate(t_stack *stack)
{
	int		popped;
	
	popped = pop_bottom(stack);
	put(stack, popped);
	printf("rra\n");
}

void	print_stack(char *prefix, t_stack *stack)
{
	t_node *node;

	node = stack->top;
	printf("%s : ", prefix);
	if (!node) {
		printf("\n");
		return ;
	}
	while (node->prev)
	{
		printf("%c -> ", node->data);
		node = node->prev;
	}
	printf("%c\n", node->data);
}
