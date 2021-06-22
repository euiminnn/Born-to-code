/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:06:22 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 18:49:03 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char ab)
{
	int		popped;

	popped = pop(stack, ab);
	put_bottom(stack, popped);
	printf("r%c\n", ab);
}

void	rrotate(t_stack *stack, char ab)
{
	int		popped;

	popped = pop_bottom(stack);
	put(stack, popped);
	printf("rr%c\n", ab);
}
