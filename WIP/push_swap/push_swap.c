/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 06:17:08 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *stack, int dup)
{
	t_node	*node;

	node = stack->top;
	if (!node)
	{
		return (1);
	}
	while (node->prev)
	{
		if (dup == node->data)
			return (0);
		node = node->prev;
	}
	if (dup == node->data)
		return (0);
	return (1);
}

int check_input_error(t_stack *stack, char *num)
{
	long long integer;

	integer = ft_atoi(num);
	if (!(ft_isdigit(num)))
		return (1);
	if (!(check_dup(stack, integer)))
		return (1);
	if (!(integer <= 2147483647
		&& integer >= -2147483648))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = stack_init();
	b = stack_init();

	i = argc - 1;
	while (i > 0)
	{
		if (check_input_error(a, argv[i]))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		put(a, ft_atoi(argv[i]));
		i--;
	}
	if (a->size == 3)
	{
		sort_three(a, b, 'a');
	}
	else
		a_to_b(a, b, a->size);
	// printf("a_to_b result\n");
	//	print_stack("a", a);
	//	print_stack("b", b);
}
