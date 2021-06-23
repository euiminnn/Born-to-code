/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:36:48 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 04:26:10 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *data, int up, int down)
{
	int i;
	int j;
	int key;
	int temp;

	if (up < down)
	{
		i = up;
		j = down + 1;
		key = data[up];
		while (i < j)
		{
			i++;
			j--;
			while (data[i] < key)
			{
				i++;
			}
			while (data[j] > key)
			{
				j--;
			}
			if (i < j)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		temp = data[up];
		data[up] = data[j];
		data[j] = temp;
		quick_sort (data, up, j-1);
		quick_sort (data, j+1, down);
	}
}

int*	stack_to_array(t_stack *stack)
//void	get_pivot(t_stack *stack)
{
	//int arr[stack->size];
	int *arr;
	t_node *node;
	
	arr = (int *)malloc(sizeof(stack->size));
	node = stack->top;
	printf("stack size = %d\n", stack->size);
	if (!node)
	{
		printf("empty stack\n");
		free(arr);	//맞나???
		return arr;
	}
	int i = 0;
	while (node -> prev)
	{
		arr[i++] = node->data;
		node = node->prev;
	}
	arr[i] = node->data;

	quick_sort(arr, 0, stack->size - 1);
	free(arr);	//???
	return arr;
}

int*	get_pivot(t_stack *stack)
{
	int *pivot;
	int *arr;

	arr = stack_to_array(stack);
	pivot = (int*)malloc(sizeof(int) * 2);
	
	if (pivot == NULL)
		return pivot;

	//If I deactivate these two lines, I get my stack sorted but wrong pivots. Else, I get correct pivots but the stack isn't sorted yet.
	//pivot[0] = arr[stack->size / 3];
	//pivot[1] = arr[stack->size * 2 / 3];

	int i;
	i = 0;
	while (i < stack->size)
	{
		/*
		if (arr[i] == pivot[0] || arr[i] == pivot[1])
			printf("p->");
		else
			printf("   ");
		*/
		printf("%d\n", arr[i++]);
	}

	free(pivot);	//?????
	return (pivot);
}
