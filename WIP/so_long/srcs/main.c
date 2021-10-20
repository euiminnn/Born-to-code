/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/10/20 15:34:44 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define STEP 48

void	param_init(t_global *g)
{
	g->param.x = g->start_x;
	g->param.y = g->start_y;
}

void	end_game(t_global *g)
{
	if (g->arr[g->param.y / STEP][g->param.x / STEP] == 'E' \
			&& g->item == g->heart)
	{
		free(g->arr);
		exit(0);
	}
}

int	init_game(char *map, t_global *g)
{
	g->row = count_row(map);
	if (g->row < 0)
		return (0);
	g->arr = readfile(map, g->row);
	g->column = ft_strlen(g->arr[0]);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->column * STEP, \
			g->row * STEP, "mushroom");
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &mouse_press, g);
	load_image(g);
	init_map(g);
	param_init(g);
	return (1);
}

int	main(int argc, char **argv)
{
	t_global	g;
	char		*map;

	map = argv[1];
	if (argc != 2 || !is_valid_file_type(map, ".ber"))
	{
		printf("Error\n");
		return (0);
	}
	ft_bzero(&g, sizeof(g));
	if (init_game(map, &g) == 0)
	{
		printf("Error\n");
		return (0);
	}
	if (parse_map(g.arr, g.row, g.column))
		mlx_loop(g.mlx);
	else
		printf("Error\n");
	free(g.arr);
}
