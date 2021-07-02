/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:52:49 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 10:45:09 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int		is_sorted(t_stack **a)
{
	/*
	int *arr;

	arr = (int *)malloc(sizeof(int) * (a->size));
	stack_to_array(a, arr, a->size);
	int i = 0;
	while (i < (a->size) -1)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		if (arr[i] < arr[i+1])
			i++;
		else
			return (0);
	}
	*/
	t_node *node;

	node = (*a)->top;
/*	
	printf("!!data: %d\n", node->data);
	printf("!!data: %d\n", node->prev->data);
	printf("!!data: %d\n", node->prev->prev->data);
	printf("!!data: %d\n", node->prev->prev->prev->data);
	printf("!!size: %d\n", (*a)->size);
*/
	while ((*a)->size > 1)
	{
		printf("data: %d\n", node->data);
		if (node->data < node->prev->data)
			((*a)->size)--;
		else
			return (0);
		node = node->prev;
	}
	printf("sorted\n");
	return (1);
}
