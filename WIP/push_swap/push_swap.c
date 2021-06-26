/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/26 21:42:13 by echung           ###   ########.fr       */
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

//int check_int(t_stack *stack, int integer)

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
		if (!(ft_atoi(argv[i]) <= 2147483647 && ft_atoi(argv[i]) >= -2147483648))
		{
			write(2, "Error\n", 6);
			return -1;
		}	
		i--;
	}
	i = argc - 1;
	while (i > 0)
	{
		if (check_dup(a, ft_atoi(argv[i])))
		{
			write(2, "Error\n", 6);
			return -1;
		}	
		put(a, ft_atoi(argv[i]));
		i--;
	}
	if (a->size == 3)
		sort_three(a, b, 'a');
	else
		a_to_b(a, b, a->size);
	//printf("a_to_b result\n");
	print_stack("a", a);
	print_stack("b", b); }
