/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:26 by echung            #+#    #+#             */
/*   Updated: 2021/06/25 21:37:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack *main, t_stack *sub, char ab)
{
    int one = main->top->data;
    int two = main->top->prev->data;
    int three = main->top->prev->prev->data;

    if (two < one && two < three && one < three)
    {
        swap(main, sub, ab);
    }
    else if (three < one && three < two && two < one)
    {
        swap(main, sub, ab);
        rrotate(main, ab);
    }
    else if (two < one && two < three && three < one)
    {
        rotate(main, ab);
    }
    else if (one < two && one < three && three < two)
    {
        swap(main, sub, ab);
        rotate(main, ab);
    }
    else if (one < two && three < two && three < one)
    {
        rrotate(main, ab);
	}
}
