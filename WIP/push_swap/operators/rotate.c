/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:06:22 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 05:31:12 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char ab)
{
	int	popped;

	if (stack->size != 0)
	{
		popped = pop(stack);
		put_bottom(stack, popped);
		printf("r%c\n", ab);
	}
}

void	rrotate(t_stack *stack, char ab)
{
	int	popped;

	if (stack->size != 0)
	{
		popped = pop_bottom(stack);
		put(stack, popped);
		printf("rr%c\n", ab);
	}
}

void	rrrotate(t_stack *main, t_stack *sub)
{
	int	popped;

	if (main->size != 0 && sub->size != 0)
	{
		popped = pop_bottom(main);
		put(main, popped);
		popped = pop_bottom(sub);
		put(sub, popped);
		printf("rrr\n");
	}
}
