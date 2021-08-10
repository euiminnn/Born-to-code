/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/08/10 18:22:58 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//#define X_EVENT_KEY_PRESS 2
//#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17 // exit key code

// Mac key code example
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
/*
	void			*mlx;
	void			*win;
	t_param			param;
	void			*img_w1;
	void			*img_w3;
	void			*back;
	void			*tree;
	void			*portal;
	void			*heart_r;
	int				heart;
	char			**arr;
	int				start_x;
	int				start_y;
	int				row;
	int				column;
	int				collectibles;
*/

void	param_init(t_global *g)
{
	g->param.x = g->start_x;
	g->param.y = g->start_y;
	g->param.str[0] = 'a';
	g->param.str[1] = 'b';
	g->param.str[2] = '\0';
}

void	end_game(t_global *g)
{
	if (g->arr[g->param.y / 48][g->param.x / 48] == 'E' \
			&& g->heart == g->collectibles)
	{
		free(g->arr);
		exit(0);
	}
}

void	get_collectibles(t_global *g)
{
	if (g->arr[g->param.y / 48][g->param.x / 48] == 'C')
	{
		g->heart++;
		g->arr[g->param.y / 48][g->param.x / 48] = '0';
	}
}

int	key_press(int keycode, t_global *g)
{
	if (keycode == KEY_W || keycode == KEY_S)
	{
		g->param.y -= ((keycode == KEY_W) - (keycode == KEY_S)) * 48;
		if (g->arr[g->param.y / 48][g->param.x / 48] == '1')
			g->param.y += ((keycode == KEY_W) - (keycode == KEY_S)) * 48;
	}
	else if (keycode == KEY_D || keycode == KEY_A)
	{
		g->param.x += ((keycode == KEY_D) - (keycode == KEY_A)) * 48;
		if (g->arr[g->param.y / 48][g->param.x / 48] == '1')
			g->param.x -= ((keycode == KEY_D) - (keycode == KEY_A)) * 48;
	}
	else if (keycode == KEY_ESC)
	{
		free(g->arr);
		exit(0);
	}
	get_collectibles(g);
	mlx_put_image_to_window(g->mlx, g->win, g->back, 0, 0);
	edit_map(g);
	end_game(g);
	return (0);
}

int	main(void)
{
	t_global	g;

	ft_bzero(&g, sizeof(g));
	g.mlx = mlx_init();
	g.row = count_row("map.ber");
	g.arr = readfile("map.ber", g.row);
	g.column = ft_strlen(g.arr[0]);
	g.win = mlx_new_window(g.mlx, g.row * 48, g.column * 48, "mushroom");
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &key_press, &g);
	load_image(&g);
	init_map(&g);
	param_init(&g);
	if (parse_map(g.arr, g.row, g.column))
		mlx_loop(g.mlx);
	else
		printf("🚫 Error: invalid map\n");
	free(g.arr);
}
