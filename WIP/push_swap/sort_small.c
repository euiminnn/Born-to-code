/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:26 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 16:03:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *main, t_stack *sub)
{
	int	one;
	int	two;
	int	three;

	one = main->top->data;
	two = main->top->prev->data;
	three = main->top->prev->prev->data;
	if (two < one && two < three && one < three)
	{
		swap(main, sub, 'a');
	}
	else if (three < one && three < two && two < one)
	{
		swap(main, sub, 'a');
		rrotate(main, 'a');
	}
	else if (two < one && two < three && three < one)
		rotate(main, 'a');
	else if (one < two && one < three && three < two)
	{
		swap(main, sub, 'a');
		rotate(main, 'a');
	}
	else if (one < two && three < two && three < one)
		rrotate(main, 'a');
}

void	sort_five(t_stack *main, t_stack *sub)
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
		if (arr[0] == node->data || arr[1] == node->data)
			push(main, sub, 'b');
		else
			rotate(main, 'a');
		i++;
	}
	sort_three(main, sub);
	push(sub, main, 'a');
	push(sub, main, 'a');
	if (main->top->data > main->top->prev->data)
		swap(main, sub, 'a');
	free(arr);
}
