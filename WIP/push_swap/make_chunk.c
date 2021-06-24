/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:45:11 by echung            #+#    #+#             */
/*   Updated: 2021/06/25 02:41:34 by echung           ###   ########.fr       */
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

void	b_to_a(t_stack *a, t_stack *b, int len)
{
	int	*pivot;
	int	count_rb;
	int	count_pa;
	int	count_ra;

	pivot = get_pivot(b, len);
	printf("[b_to_a] pivots are: %d, %d\n", pivot[0], pivot[1]);
	count_rb = 0;
	count_pa = 0;
	count_ra = 0;
	printf("[b_to_a] pivots are: %d %d\n", pivot[0], pivot[1]);
	if (len < 3)
	{
		sort_three(b, a, 'b');
		while (len)
			push(b, a, 'a');
		return ;
	}
	while (len)
	{
		if (b->top->data < pivot[0])
		{
			rotate(b, 'b');
			count_rb++;
		}
		else
		{
			push(b, a, 'a');
			count_pa++;
			if (b->top->data >= pivot[1])
			{
				rotate(a, 'a');
				count_ra++;
			}
		}
	}
	a_to_b(a, b, count_pa - count_ra);

	int c_min = min(count_ra, count_rb);
	
	while (c_min)
	{
		rrrotate(a, b);
		c_min--;
	}
	if (count_ra > count_rb)
		rotate(a, 'a');
	else if (count_ra < count_rb)
		rotate(b, 'b');
	a_to_b(a, b, count_rb);
	b_to_a(a, b, count_ra);

}

void	a_to_b(t_stack *a, t_stack *b, int len)
{
	int *pivot;
	int	count_ra;
	int	count_pb;
	int	count_rb;
/*
	if (ab == 'a')
		sub_ab = 'b';
	else
		sub_ab = 'a';
*/	
	pivot = get_pivot(a, len);
	printf("[a_to_b] pivots are: %d, %d\n", pivot[0], pivot[1]);

	count_ra = 0;
	count_pb = 0;
	count_rb = 0;
/* ERROR HERE
	if (len < 3)
	{
		if (len == 3)
		{
			printf("error here?\n");
			sort_three(a, b, 'a');
			printf("error here!!!!\n");
		}
		else if (len == 2 && a -> top -> data > a -> top -> prev -> data)
		{
			swap(a, b, 'a');
		}
		return ;
	}
*/
	while (len)
	{
		if (a -> top -> data >= pivot[1])
		{
			rotate(a, 'a');
			count_ra++;
		}
		else
		{
			push(a, b, 'b');
			count_pb++;
			if (b -> top -> data >= pivot[0])
			{
				rotate(b, 'b');
				count_rb++;
			}
		}
		len--;
	}
	int c_min = min(count_ra, count_rb);
	
	while (c_min)
	{
		rrrotate(a, b);
		c_min--;
	}
	if (count_ra > count_rb)
		rotate(a, 'a');
	else if (count_ra < count_rb)
		rotate(b, 'b');
	a_to_b(a, b, count_ra);
	b_to_a(a, b, count_rb);
	b_to_a(a, b, count_pb - count_rb);
	free(pivot);
}
