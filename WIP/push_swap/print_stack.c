/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:09:15 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 22:01:06 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(char *prefix, t_stack *stack)
{
	t_node *node;

	node = stack->top;
	printf("%s : ", prefix);
	if (!node)
	{
		printf("\n");
		return ;
	}
	while (node->prev)
	{
		printf("%d -> ", node->data);
		node = node->prev;
	}
	printf("%d\n", node->data);
}
