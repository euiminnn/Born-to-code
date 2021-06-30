/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:49:54 by echung            #+#    #+#             */
/*   Updated: 2021/07/01 01:01:13 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to, char ab, t_print *p)
{
	int	popdata;

	if (from->size != 0)
	{
		popdata = pop(from);
		put(to, popdata);
		if (ab == 'a')
			pput(p, "pa");
		else if (ab == 'b')
			pput(p, "pb");
	}
}
