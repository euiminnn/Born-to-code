/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:24:18 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 20:37:12 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	edit_map(t_global *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->row)
	{
		j = 0;
		while (j < g->column)
		{
			if (g->arr[i][j] == '1')
				img_to_win(g, g->tree, 48 * j, 48 * i);
			if (g->arr[i][j] == 'C')
				img_to_win(g, g->heart_r, 48 * j, 48 * i);
			if (g->arr[i][j] == 'E')
				img_to_win(g, g->portal, 48 * j, 48 * i);
			j++;
		}
		i++;
	}
	if ((g->param.x / 48) % 2 == 0)
		img_to_win(g, g->img_w1, g->param.x, g->param.y);
	else
		img_to_win(g, g->img_w3, g->param.x, g->param.y);
}

void	init_map(t_global *g)
{
	img_to_win(g, g->back, 0, 0);
	g->iter.i = -1;
	while ((g->iter.i)++ < g->row - 1)
	{
		g->iter.j = -1;
		while ((g->iter.j)++ < g->column - 1)
		{
			if (g->arr[g->iter.i][g->iter.j] == '1')
				img_to_win(g, g->tree, 48 * g->iter.j, 48 * g->iter.i);
			if (g->arr[g->iter.i][g->iter.j] == 'C')
			{
				img_to_win(g, g->heart_r, 48 * g->iter.j, 48 * g->iter.i);
				g->heart++;
			}
			if (g->arr[g->iter.i][g->iter.j] == 'E')
				img_to_win(g, g->portal, 48 * g->iter.j, 48 * g->iter.i);
			if (g->arr[g->iter.i][g->iter.j] == 'P')
			{
				img_to_win(g, g->img_w1, 48 * g->iter.j, 48 * g->iter.i);
				g->start_x = 48 * g->iter.j;
				g->start_y = 48 * g->iter.i;
			}
		}
	}
}
