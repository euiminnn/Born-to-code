/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:26 by echung            #+#    #+#             */
/*   Updated: 2021/06/25 02:32:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack *main, t_stack *sub, char ab)
{
	print_stack("main", main);
	print_stack("sub", sub);
    int one = main->top->data;
	printf("one: %d", one);
    int two = main->top->prev->data;
	printf("two: %d", two);
    int three = main->top->prev->prev->data;
	printf("three: %d", three);

    if (two < one && two < three && one < three)
    {
		printf("one\n");
        swap(main, sub, ab);
    }
    else if (three < one && three < two && two < one)
    {
		printf("two\n");
        swap(main, sub, ab);
        rrotate(main, ab);
    }
    else if (two < one && two < three && three < one)
    {
		printf("three\n");
        rotate(main, ab);
    }
    else if (one < two && one < three && three < two)
    {
		printf("four\n");
        swap(main, sub, ab);
        rotate(main, ab);
    }
    else if (one < two && three < two && three < one)
    {
		printf("five\n");
        rrotate(main, ab);
	}
}
