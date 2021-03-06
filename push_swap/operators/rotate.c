/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:06:22 by echung            #+#    #+#             */
/*   Updated: 2021/07/01 01:00:35 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char ab, t_print *p)
{
	int	popped;

	if (stack->size != 0)
	{
		popped = pop(stack);
		put_bottom(stack, popped);
		if (ab == 'a')
			pput(p, "ra");
		else if (ab == 'b')
			pput(p, "rb");
	}
}

void	rrotate(t_stack *stack, char ab, t_print *p)
{
	int	popped;

	if (stack->size != 0)
	{
		popped = pop_bottom(stack);
		put(stack, popped);
		if (ab == 'a')
			pput(p, "rra");
		else if (ab == 'b')
			pput(p, "rrb");
	}
}

void	rrrotate(t_stack *main, t_stack *sub, t_print *p)
{
	int	popped;

	if (main->size != 0 && sub->size != 0)
	{
		popped = pop_bottom(main);
		put(main, popped);
		popped = pop_bottom(sub);
		put(sub, popped);
		pput(p, "rrr");
	}
}
