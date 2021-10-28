/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:45:36 by echung            #+#    #+#             */
/*   Updated: 2021/10/28 14:27:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_param(t_global *g)
{
	g->param.x = g->start_x;
	g->param.y = g->start_y;
}

static void	init_global(char *map, t_global *g)
{
	g->row = count_row(map);
	if (g->row == -1)
		return ;
	g->arr = read_map(map, g->row);
	if (g->arr == 0)
		return ;
	g->column = ft_strlen(g->arr[0]);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->column * STEP, \
			g->row * STEP, "mushroom");
}

int	init_game(char *map, t_global *g)
{
	init_global(map, g);
	if (g->row == -1 || g->arr == 0)
		return (0);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &mouse_press, g);
	load_image(g);
	init_map(g);
	init_param(g);
	return (1);
}
