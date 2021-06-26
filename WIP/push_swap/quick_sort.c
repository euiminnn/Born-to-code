/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:49:57 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 05:02:09 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	quick_sort(int *data, int up, int down)
{
	int	i;
	int	j;
	int	key;
	int	temp;

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
*/

void	swap_m(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int		partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i =
		(low -
			1); // Index of smaller element and indicates the right position of pivot found so far
	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap_m(&arr[i], &arr[j]);
		}
	}
	swap_m(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void	quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		pi = partition(arr, low, high);
		// Separately sort elements before
		// partition and after partition
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
