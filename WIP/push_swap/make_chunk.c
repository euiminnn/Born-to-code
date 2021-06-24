/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:45:11 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 22:52:49 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	make_chunk(t_stack *main, t_stack *sub, int len, char ab)
{
	int *pivot;
	int	size;
	int	count_main;
	int	count_sub;
	char sub_ab;

	if (ab == 'a')
		sub_ab = 'b';
	else
		sub_ab = 'a';
	
	pivot = get_pivot(main, len);
	printf("[make_chunk] pivots are: %d, %d\n", pivot[0], pivot[1]);

	size = len;
	count_main = 0;
	count_sub = 0;
	while (size)
	{
		if (main -> top -> data >= pivot[1])
		{
			rotate(main, ab);
			count_main++;
		}
		else
		{
			push(main, sub, sub_ab);
			if (sub -> top -> data >= pivot[0])
			{
				rotate(sub, sub_ab);
				count_sub++;
			}
		}
		size--;
	}
	int c_min = min(count_main, count_sub);
	
	while (c_min)
	{
		rrrotate(main, sub);
		c_min--;
	}
	if (count_main > count_sub)
		rotate(main, ab);
	else if (count_main < count_sub)
		rotate(sub, sub_ab);
	free(pivot);
}
