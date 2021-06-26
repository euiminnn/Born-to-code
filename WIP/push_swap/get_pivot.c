/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:36:48 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 04:59:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivot(t_stack *stack, int len, int *pivot)
{
	int		*arr;
	t_node	*node;
	int		i;

	arr = (int *)malloc(sizeof(int) * len);
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
	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	free(arr);
}
