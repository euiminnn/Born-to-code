/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/08/13 15:52:28 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_init(t_global *g)
{
	g->param.x = g->start_x;
	g->param.y = g->start_y;
}

void	end_game(t_global *g)
{
	if (g->arr[g->param.y / 48][g->param.x / 48] == 'E' \
			&& g->item == g->heart)
	{
		free(g->arr);
		exit(0);
	}
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
	g.win = mlx_new_window(g.mlx, g.column * 48, g.row * 48, "mushroom");
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &key_press, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 0, &mouse_press, &g);
	load_image(&g);
	init_map(&g);
	param_init(&g);
	if (parse_map(g.arr, g.row, g.column))
		mlx_loop(g.mlx);
	else
		printf("🚫 Error: invalid map\n");
	free(g.arr);
}
