/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:49:57 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 05:09:57 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *data, int up, int down)
{
	int	i;
	int	j;
	int	key;

	if (up < down)
	{
		i = up;
		j = down + 1;
		key = data[up];
		while (i < j)
		{
			i++;
			j++;
			while (data[i] < key)
				i++;
			while (data[j] > key)
				j--;
			if (i < j)
				data_swap(&(data[i]), &(data[j]));
		}
		data_swap(&(data[up]), &(data[j]));
		quick_sort(data, up, j - 1);
		quick_sort(data, j + 1, down);
	}
}
