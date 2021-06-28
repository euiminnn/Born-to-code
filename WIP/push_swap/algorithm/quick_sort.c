/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:49:57 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 20:13:43 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_data(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		quick_sort(int arr[], int up, int down)
{
	int	i;
	int	j;
	int	pivot;

	i = up;
	j = down;
	pivot = arr[(up + down) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			if (i != j)
				swap_data(&(arr[i]), &(arr[j]));
			i++;
			j--;
		}
	}
	if (up < j)
		quick_sort(arr, up, j);
	if (i < down)
		quick_sort(arr, i, down);
}
