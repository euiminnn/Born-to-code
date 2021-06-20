/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/12 06:01:31 by echung           ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		put(a, *argv[i]);
		i++;
	}
	if (argc == 4)
	{
		sort_three(a, b);
	}
	
	printf("Stack A:\n");
	printf("%c\n", a->top->data);
	printf("%c\n", a->top->prev->data);
	printf("%c\n", a->top->prev->prev->data);
/*
	printf("%c\n", a->top->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->prev->data);
	
	printf("<reverse rotate A>\n");
	rrotate(a);

	printf("Stack A:\n");
	printf("%c\n", a->top->data);
	printf("%c\n", a->top->prev->data);
	printf("%c\n", a->top->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->prev->data);

	printf("<reverse rotate A>\n");
	rrotate(a);

	printf("Stack A:\n");
	printf("%c\n", a->top->data);
	printf("%c\n", a->top->prev->data);
	printf("%c\n", a->top->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->prev->data);
*/
	//printf("bottom of Stack A:\n");
	//printf("%c\n", a->bottom->data);
	/*
	printf("Stack B:\n");
	printf("%c\n", b->top->data);
	printf("%c\n", b->top->prev->prev->data);
	printf("%c\n", b->top->prev->prev->data);

	printf("\n<swap A>\n");
	swap(a, b);
	printf("Stack A:\n");
	printf("%c\n", a->top->data);
	printf("%c\n", a->top->prev->data);
	printf("%c\n", a->top->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->prev->data);
	printf("Stack B:\n");
	printf("%c\n", b->top->data);
	printf("%c\n", b->top->prev->data);
	printf("%c\n", b->top->prev->prev->data);
*/
}
