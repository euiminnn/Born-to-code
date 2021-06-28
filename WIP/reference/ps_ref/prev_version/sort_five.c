/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:39:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 18:50:52 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	char a_big;
	char a_small;
	char b_one;
	char b_two;

	push(a, b, 'b');
	push(a, b, 'b');
	
	sort_three(a, b);
	
	a_big = a->top->prev->prev->data;
	a_small = a->top->data;
	
	b_one = b->top->data;
	b_two = b->top->prev->data;
	
	if (b_one > b_two)
	{
		if (a_big < b_one) //2->3->4, 5->1
		{
			push(b, a, 'a');
			rotate(a, 'a'); //4 done
		}
		else if (a_big > b_one)
		{
			rrotate(a, 'a');
			a_big = a->top->prev->prev->data;
			b_one = b->top->data;
			if (a_big < b_one) //1->3->5, 4->2
			{
				push(b, a, 'a');
				rotate(a, 'a');
				rotate(a, 'a');
			}
			else //1->4->5, 3->2
			{
				rrotate(a, 'a');
				push(b, a, 'a');
				rrotate(a, 'a');
			}
			rotate(a, 'a');
			push(b, a, 'a');
			rrotate(a, 'a');
		}
	}
}
