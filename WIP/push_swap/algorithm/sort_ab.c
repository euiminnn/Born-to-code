/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:45:11 by echung            #+#    #+#             */
/*   Updated: 2021/07/01 15:02:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RA 0
#define RB 1
#define PA 2
#define PB 3

static int	last_step(t_stack *a, t_stack *b, int *count, t_print *p)
{
	int	i;

	i = count[RA];
	if (count[RB] < count[RA])
		i = count[RB];
	while (i--)
		rrrotate(a, b, p);
	if (count[RA] > count[RB])
		rrotate(a, 'a', p);
	else if (count[RA] < count[RB])
		rrotate(b, 'b', p);
	while (i-- > 0)
		rrotate(b, 'b', p);
	a_to_b(a, b, count[RA], p);
	b_to_a(a, b, count[RB], p);
	return (1);
}

static int	b_to_a_small(t_stack *a, t_stack *b, int len, t_print *p)
{
	if (len == 0)
		return (1);
	if (len == 2)
	{
		if (b->top->data < b->top->prev->data)
			swap(b, a, 'b', p);
		push(b, a, 'a', p);
	}
	push(b, a, 'a', p);
	return (1);
}

static int	a_to_b_small(t_stack *a, t_stack *b, int len, t_print *p)
{
	if (len == 2 && a->top->data > a->top->prev->data)
		swap(a, b, 'a', p);
	return (1);
}

int			b_to_a(t_stack *a, t_stack *b, int len, t_print *p)
{
	int	pivot[2];
	int	count[4];

	if (len < 3)
		return (b_to_a_small(a, b, len, p));
	ft_bzero(count, sizeof(int) * 4);
	get_pivot(b, len, pivot);
	while (len--)
	{
		if (b->top->data < pivot[0])
		{
			rotate(b, 'b', p);
			count[RB]++;
			continue ;
		}
		push(b, a, 'a', p);
		count[PA]++;
		if (a->top->data < pivot[1])
		{
			rotate(a, 'a', p);
			count[RA]++;
		}
	}
	a_to_b(a, b, count[PA] - count[RA], p);
	return (last_step(a, b, count, p));
}

int			a_to_b(t_stack *a, t_stack *b, int len, t_print *p)
{
	int	pivot[2];
	int	count[4];

	if (len < 3)
		return (a_to_b_small(a, b, len, p));
	ft_bzero(count, sizeof(int) * 4);
	get_pivot(a, len, pivot);
	while (len--)
	{
		if (a->top->data >= pivot[1])
		{
			rotate(a, 'a', p);
			count[RA]++;
			continue ;
		}
		push(a, b, 'b', p);
		count[PB]++;
		if (b->top->data >= pivot[0])
		{
			rotate(b, 'b', p);
			count[RB]++;
		}
	}
	last_step(a, b, count, p);
	return (b_to_a(a, b, count[PB] - count[RB], p));
}
