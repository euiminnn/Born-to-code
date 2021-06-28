/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:45:11 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 16:06:26 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RA 0
#define RB 1
#define PA 2
#define PB 3

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	b_to_a(t_stack *a, t_stack *b, int len)
{
	int	pivot[2];
	int	count[4];
	int	i;

	count[RB] = 0;
	count[PA] = 0;
	count[RA] = 0;
	if (len < 3)
	{
		if (len == 0)
			return ;
		if (len == 2)
		{
			if (b->top->data < b->top->prev->data)
				swap(b, a, 'b');
			push(b, a, 'a');
		}
		push(b, a, 'a');
		return ;
	}
	get_pivot(b, len, pivot);
	while (len--)
	{
		if (b->top->data < pivot[0])
		{
			rotate(b, 'b');
			count[RB]++;
		}
		else
		{
			push(b, a, 'a');
			count[PA]++;
			if (a->top->data < pivot[1])
			{
				rotate(a, 'a');
				count[RA]++;
			}
		}
	}
	a_to_b(a, b, count[PA] - count[RA]);
	i = min(count[RA], count[RB]);
	while (i--)
		rrrotate(a, b);
	i = count[RA] - count[RB];
	while (i-- > 0)
		rrotate(a, 'a');
	i = count[RB] - count[RA];
	while (i-- > 0)
		rrotate(b, 'b');
	a_to_b(a, b, count[RA]);
	b_to_a(a, b, count[RB]);
}

void	a_to_b(t_stack *a, t_stack *b, int len)
{
	int	pivot[2];
	int	count[4];
	int	i;

	count[RA] = 0;
	count[PB] = 0;
	count[RB] = 0;
	if (len < 3)
	{
		if (len == 2 && a->top->data > a->top->prev->data)
			swap(a, b, 'a');
		return ;
	}
	get_pivot(a, len, pivot);
	while (len--)
	{
		if (a->top->data >= pivot[1])
		{
			rotate(a, 'a');
			count[RA]++;
		}
		else
		{
			push(a, b, 'b');
			count[PB]++;
			if (b->top->data >= pivot[0])
			{
				rotate(b, 'b');
				count[RB]++;
			}
		}
	}
	i = min(count[RA], count[RB]);
	while (i--)
		rrrotate(a, b);
	i = count[RA] - count[RB];
	while (i-- > 0)
		rrotate(a, 'a');
	i = count[RB] - count[RA];
	while (i-- > 0)
		rrotate(b, 'b');
	a_to_b(a, b, count[RA]);
	b_to_a(a, b, count[RB]);
	b_to_a(a, b, count[PB] - count[RB]);
}
