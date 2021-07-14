/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:52:49 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 18:17:02 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;
	int		len;

	len = a->size;
	node = a->top;
	while (len > 1)
	{
		if (node->data < node->prev->data)
			len--;
		else
			return (0);
		node = node->prev;
	}
	return (1);
}
