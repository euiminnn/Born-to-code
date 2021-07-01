/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:06:22 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 03:44:46 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack *stack)
{
	int	popped;

	if (stack->size != 0)
	{
		popped = pop(stack);
		put_bottom(stack, popped);
	}
}

void	rrotate(t_stack *stack)
{
	int	popped;

	if (stack->size != 0)
	{
		popped = pop_bottom(stack);
		put(stack, popped);
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
	}
}
