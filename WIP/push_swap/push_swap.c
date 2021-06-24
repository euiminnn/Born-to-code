/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 16:47:45 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack* a;
	t_stack* b;
	int	i;

    a = stack_init();
    b = stack_init();

//	printf("argc = %d\n", argc);

	i = argc - 1;
	while (i > 0)
	{
		put(a, ft_atoi(argv[i]));
		i--;
	}
	
	make_chunk(a, b);

	//int* pivot;
	//pivot = get_pivot(a);
	//printf("pivots are: %d %d\n", pivot[0], pivot[1]);

	//print_stack("a", a);
	//print_stack("b", b);

//	print_stack("a", a);
//	print_stack("b", b);
	
}
