/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:45:11 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 17:24:02 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_chunk(t_stack *main, t_stack *sub)
{
	int *pivot;
	int	size;
	int	count_main;
	int	count_sub;
	
	pivot = get_pivot(main);
	printf("pivots are: %d, %d", pivot[0], pivot[1]);

	size = main->size;
	count_main = 0;
	count_sub = 0;
	while (size)
	{
		if (main -> top -> data >= pivot[1])
		{
			rotate(main, 'a');
			count_main++;
		}
		else
		{
			push(main, sub, 'b');
			if (sub -> top -> data >= pivot[0])
			{
				rotate(sub, 'b');
				count_sub++;
			}
		}
	}
	while (min(count_main, count_sub))
	{
		rrrotate(main, sub);
	}
	if () //크기가 차이날 경우 ra 혹은 rb 한 번 더 실행
	{
	}
}
