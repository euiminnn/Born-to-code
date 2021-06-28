/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:44 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 06:16:34 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *main, t_stack *sub, char ab)
{
	char	popped;

	if (main->size != 0)
	{
		push(main, sub, 0);
		popped = pop(main);
		push(sub, main, 0);
		put(main, popped);
		printf("s%c\n", ab);
	}
}
