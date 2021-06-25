/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:36:48 by echung            #+#    #+#             */
/*   Updated: 2021/06/25 19:33:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int*	stack_to_array(t_stack *stack, int len)
{
	//int arr[stack->size];
	int *arr;
	t_node *node;
	
	arr = (int *)malloc(sizeof(int) * len);
	node = stack->top;
	if (!node)
	{
		printf("empty stack\n");
		free(arr);
		return arr;
	}
	int i = 0;
	while (node -> prev && i < len)
	{
		arr[i++] = node->data;
		node = node->prev;
	}
	arr[i] = node->data;
	
	quick_sort(arr, 0, len - 1);
	//printf("error here\n");
	//free(arr);	//???
	return arr;
}

int*	get_pivot(t_stack *stack, int len)
{
	int *pivot;
	int *arr;

	arr = stack_to_array(stack, len);
	pivot = (int *)malloc(sizeof(int) * 2);
	
	if (pivot == NULL)
		return pivot;

	pivot[0] = arr[len / 3];
	pivot[1] = arr[len * 2 / 3];
	
	
	//printf("array ad = %p\n", arr);
	//printf("pivot ad = %p\n", pivot);
	
	/*
	int i;
	i = 0;
	while (i < len)
	{
		if (arr[i] == pivot[0] || arr[i] == pivot[1])
			printf("p->");
		else
			printf("   ");
		printf("%d\n", arr[i++]);
	}
	*/
	free(arr);
	return (pivot);
}
