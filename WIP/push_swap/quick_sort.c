/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:36:48 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 22:21:54 by echung           ###   ########.fr       */
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

void	stack_to_array(t_stack *stack)
{
	int arr[stack->size];
	t_node *node;
	node = stack->top;
	printf("stack size = %d\n", stack->size);
	if (!node)
	{
		printf("empty stack\n");
		return ;
	}
	int i = 0;
	while (node -> prev)
	{
		arr[i++] = node->data;
		node = node->prev;
	}
	arr[i] = node->data;

	quick_sort(arr, 0, stack->size - 1);
	
	i = 0;
	while (i < stack->size)
	{
		printf("^__^ %d\n", arr[i++]);
	}
	int pivot_one;
	int pivot_two;

	pivot_one = arr[stack->size / 3];
	pivot_two = arr[stack->size * 2 / 3];
	printf("pivot one = %d\n", pivot_one);
	printf("pivot two = %d\n", pivot_two);
}

/*
int main()
{
	int data[10] = {1, 5, 7, 8, 3, 9, 4, 2, 6, 0};

	quick_sort(data, 0, 9);
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", data[i++]);
	}
}
*/
