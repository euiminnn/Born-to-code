/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:44 by echung            #+#    #+#             */
/*   Updated: 2021/07/01 01:01:27 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *main, t_stack *sub, char ab, t_print *p)
{
	char	popped;

	if (main->size != 0)
	{
		push(main, sub, 0, p);
		popped = pop(main);
		push(sub, main, 0, p);
		put(main, popped);
		if (ab == 'a')
			pput(p, "sa");
		else if (ab == 'b')
			pput(p, "sb");
	}
}
