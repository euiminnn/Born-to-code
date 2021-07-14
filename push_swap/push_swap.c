/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/07/14 20:47:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_print	*p;

	a = stack_init();
	b = stack_init();
	p = print_init();
	if (parse_input(argc, argv, a))
	{
		if (is_sorted(a))
			return (0);
		if (a->size == 3 || a->size == 4 || a->size == 5)
			sort_small(a, b, p);
		else
			a_to_b(a, b, a->size, p);
	}
	else
		write(2, "Error\n", 6);
	print(p);
	return (0);
}
