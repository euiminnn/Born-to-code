/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:26 by echung            #+#    #+#             */
/*   Updated: 2021/06/29 03:02:34 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *main, t_stack *sub, t_print *p)
{
	int	one;
	int	two;
	int	three;

	one = main->top->data;
	two = main->top->prev->data;
	three = main->top->prev->prev->data;
	if (two < one && two < three && one < three)
		swap(main, sub, 'a', p);
	else if (three < one && three < two && two < one)
	{
		swap(main, sub, 'a', p);
		rrotate(main, 'a', p);
	}
	else if (two < one && two < three && three < one)
		rotate(main, 'a', p);
	else if (one < two && one < three && three < two)
	{
		swap(main, sub, 'a', p);
		rotate(main, 'a', p);
	}
	else if (one < two && three < two && three < one)
		rrotate(main, 'a', p);
}

static void	sort_four(t_stack *main, t_stack *sub, t_print *p)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * 4);
	stack_to_array(main, arr, 4);
	i = 0;
	while (i < 4)
	{
		node = main->top;
		if (arr[0] == node->data)
			push(main, sub, 'b', p);
		else
			rotate(main, 'a', p);
		i++;
	}
	sort_three(main, sub, p);
	push(sub, main, 'a', p);
	free(arr);
}

static void	sort_five(t_stack *main, t_stack *sub, t_print *p)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * 5);
	stack_to_array(main, arr, 5);
	i = 0;
	while (i < 5)
	{
		node = main->top;
		if (node->data == arr[0] || node->data == arr[1])
			push(main, sub, 'b', p);
		else
			rotate(main, 'a', p);
		i++;
	}
	sort_three(main, sub, p);
	push(sub, main, 'a', p);
	push(sub, main, 'a', p);
	if (main->top->data > main->top->prev->data)
		swap(main, sub, 'a', p);
	free(arr);
}

void		sort_small(t_stack *a, t_stack *b, t_print *p)
{
	if (a->size == 3)
		sort_three(a, b, p);
	else if (a->size == 4)
		sort_four(a, b, p);
	else if (a->size == 5)
		sort_five(a, b, p);
}
