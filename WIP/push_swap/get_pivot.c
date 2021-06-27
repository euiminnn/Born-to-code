/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:36:48 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 14:59:35 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_array(t_stack *stack, int *arr, int len)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 0;
	while (node->prev && i < len)
	{
		arr[i++] = node->data;
		node = node->prev;
	}
	if (i < len)
		arr[i] = node->data;
	quick_sort(arr, 0, len - 1);
}

void	get_pivot(t_stack *stack, int len, int *pivot)
{
	int		*arr;

	arr = (int *)malloc(sizeof(int) * len);
	stack_to_array(stack, arr, len);
	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	free(arr);
}
