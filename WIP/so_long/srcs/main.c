/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/08/12 00:42:30 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//#define X_EVENT_KEY_PRESS 2
//#define X_EVENT_KEY_RELEASE 3
//#define X_EVENT_KEY_EXIT 17 // exit key code

// Mac key code example
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

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

int	main(int argc, char **argv)
{
	t_global	g;

	if (argc != 2)
		return (0);
	if (!check_arg(argv[1]))
		return (0);
	ft_bzero(&g, sizeof(g));
	g.mlx = mlx_init();
	g.row = count_row(argv[1]);
	g.arr = readfile(argv[1], g.row);
	g.column = ft_strlen(g.arr[0]);
	g.win = mlx_new_window(g.mlx, g.row * 48, g.column * 48, "mushroom");
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &key_press, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 0, &key_press, &g);				//Bus Error
	load_image(&g);
	init_map(&g);
	param_init(&g);
	if (parse_map(g.arr, g.row, g.column))
		mlx_loop(g.mlx);
	else
		printf("🚫 Error: invalid map\n");
	free(g.arr);
}
