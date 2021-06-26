/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:49:57 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 05:28:48 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_data(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int arr[], int left, int right)
{
	int	L;
	int	R;
	int	pivot;

	pivot = arr[(left + right) / 2];
	L = left;
	R = right;
	while (L <= R)
	{
		while (arr[L] < pivot)
			L++;
		while (arr[R] > pivot)
			R--;
		if (L <= R)
		{
			if (L != R)
				swap_data(&(arr[L]), &(arr[R]));
			L++;
			R--;
		}
	}
	if (left < R)
		quick_sort(arr, left, R);
	if (L < right)
		quick_sort(arr, L, right);
}
