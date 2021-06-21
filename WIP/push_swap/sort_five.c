/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:39:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/21 22:33:43 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	char a_big;
	char a_small;
	char b_one;
	char b_two;

	a_big = a->top->prev->prev->data;
	a_small = a->top->data;

	push(a, b);
	push(a, b);
	
	b_one = b->top->data;
	b_two = b->top->prev->data;
	
	sort_three(a, b);

	if (b_one > b_two)
	{
		if (a_big < b_one) //2->3->4, 5->1
		{
			push(b, a);
			rotate(a); //4 done
		}
		else if (a_big > b_one)
		{
			rrotate(a);
			a_big = a->top->prev->prev->data;
			b_one = b->top->data;
			if (a_big < b_one) //1->3->5, 4->2
			{
				push(b, a);
				rotate(a);
				rotate(a);
			}
			else //1->4->5, 3->2
			{
				rrotate(a);
				push(b, a);
				rrotate(a);
				printf("here\n");
			}
		}
	}
	else
	{

	}
}
