/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:49:57 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 16:50:18 by echung           ###   ########.fr       */
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
