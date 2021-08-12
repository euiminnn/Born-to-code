/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 01:50:22 by echung            #+#    #+#             */
/*   Updated: 2021/08/13 01:50:38 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_global *g)
{
	g->movement++;
	g->param.y -= ((keycode == KEY_W) - (keycode == KEY_S)) * 48;
	g->param.x += ((keycode == KEY_D) - (keycode == KEY_A)) * 48;
	if (g->arr[g->param.y / 48][g->param.x / 48] == '1')
	{
		g->param.y += ((keycode == KEY_W) - (keycode == KEY_S)) * 48;
		g->param.x -= ((keycode == KEY_D) - (keycode == KEY_A)) * 48;
		g->movement--;
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(g->mlx, g->win);
		free(g->arr);
		exit(0);
	}
	printf("move: %d\n", g->movement);
	get_collectibles(g);
	mlx_put_image_to_window(g->mlx, g->win, g->back, 0, 0);
	edit_map(g);
	end_game(g);
	return (0);
}

int	mouse_press(t_global *g)
{
	free(g->arr);
	exit(0);
}
