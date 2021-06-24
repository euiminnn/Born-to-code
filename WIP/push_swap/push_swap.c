/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 23:18:51 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *stack, int dup)
{
	t_node *node;

	node = stack->top;
	if (!node)
	{
		return 0;
	}
	while (node->prev)
	{
		if (dup == node->data)
			return 1;
		node = node->prev;
	}
	if (dup == node->data)
		return 1;
	return 0;
}

int	main(int argc, char **argv)
{
	t_stack* a;
	t_stack* b;
	int	i;

    a = stack_init();
    b = stack_init();

	i = argc - 1;
	while (i > 0)
	{
		if (check_dup(a, ft_atoi(argv[i])))
		{
			printf("dup error\n");
			return -1;
		}
		put(a, ft_atoi(argv[i]));
		i--;
	}

	make_chunk(a, b, a->size, 'a');
	print_stack("first make chunk result", a);
	print_stack("first make chunk result", b);

	make_chunk(a, b, a->size, 'a');
	print_stack("second make chunk result", a);
	print_stack("second make chunk result", b);

	make_chunk(b, a, 2, 'b');
	print_stack("second make chunk result", a);
	print_stack("second make chunk result", b);
}
