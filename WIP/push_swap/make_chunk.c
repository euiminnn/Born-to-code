/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:45:11 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 18:25:22 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RA 0
#define RB 1
#define PA 2
#define PB 3

static int	last_step(t_stack *a, t_stack *b, int *count)
{
	int i;

	i = count[RA];
	if (count[RB] < count[RA])
		i = count[RB];
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
	return (1);
}

static int	b_to_a_small(t_stack *a, t_stack *b, int len)
{
	if (len == 0)
		return (1);
	if (len == 2)
	{
		if (b->top->data < b->top->prev->data)
			swap(b, a, 'b');
		push(b, a, 'a');
	}
	push(b, a, 'a');
	return (1);
}

static int	a_to_b_small(t_stack *a, t_stack *b, int len)
{
	if (len == 2 && a->top->data > a->top->prev->data)
		swap(a, b, 'a');
	return (1);
}

int			b_to_a(t_stack *a, t_stack *b, int len)
{
	int	pivot[2];
	int	count[4];

	ft_bzero(count, sizeof(int) * 4);
	if (len < 3)
		return (b_to_a_small(a, b, len));
	get_pivot(b, len, pivot);
	while (len--)
	{
		if (b->top->data < pivot[0])
		{
			rotate(b, 'b');
			count[RB]++;
			continue ;
		}
		push(b, a, 'a');
		count[PA]++;
		if (a->top->data < pivot[1])
		{
			rotate(a, 'a');
			count[RA]++;
		}
	}
	a_to_b(a, b, count[PA] - count[RA]);
	return (last_step(a, b, count));
}

int			a_to_b(t_stack *a, t_stack *b, int len)
{
	int	pivot[2];
	int	count[4];

	ft_bzero(count, sizeof(int) * 4);
	if (len < 3)
		return (a_to_b_small(a, b, len));
	get_pivot(a, len, pivot);
	while (len--)
	{
		if (a->top->data >= pivot[1])
		{
			rotate(a, 'a');
			count[RA]++;
			continue ;
		}
		push(a, b, 'b');
		count[PB]++;
		if (b->top->data >= pivot[0])
		{
			rotate(b, 'b');
			count[RB]++;
		}
	}
	last_step(a, b, count);
	return (b_to_a(a, b, count[PB] - count[RB]));
}
