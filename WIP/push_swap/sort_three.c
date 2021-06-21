/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:26 by echung            #+#    #+#             */
/*   Updated: 2021/06/21 21:34:28 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack *a, t_stack *b)
{
    int one = a->top->data;
    int two = a->top->prev->data;
    int three = a->top->prev->prev->data;

    if (two < one && two < three && one < three)
    {
        swap(a, b);
    }
    else if (three < one && three < two && two < one)
    {
        swap(a, b);
        rrotate(a);
    }
    else if (two < one && two < three && three < one)
    {
        rotate(a);
    }
    else if (one < two && one < three && three < two)
    {
        swap(a, b);
        rotate(a);
    }
    else if (one < two && three < two && three < one)
    {
        rrotate(a);
	}
}
