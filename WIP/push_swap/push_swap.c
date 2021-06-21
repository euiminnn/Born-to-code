/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 04:32:09 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack* a;
	t_stack* b;

    a = stack_init();
    b = stack_init();
	int	i;

	printf("argc = %d\n\n", argc);

	i = argc - 1;
	while (i > 0)
	{
		put(a, *argv[i]);
		i--;
	}

	//print_stack("a", a);
	//print_stack("b", b);

	if (argc == 4)
	{
		sort_three(a, b);
	}

	else if (argc == 6)
	{
		sort_five(a, b);
	}

	//print_stack("a", a);
	//print_stack("b", b);
	
}
