/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:44 by echung            #+#    #+#             */
/*   Updated: 2021/06/21 21:34:45 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *main, t_stack *sub)
{
    char    popped;

    push(main, sub);
    popped = pop(main);
    push(sub, main);
    put(main, popped);
}
