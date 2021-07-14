/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:49:54 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 17:22:15 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack *from, t_stack *to)
{
	int	popdata;

	if (from->size != 0)
	{
		popdata = pop(from);
		put(to, popdata);
	}
}
