/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/08/18 18:13:47 by echung           ###   ########.fr       */
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

int	init_game(char *argv1, t_global *g)
{
	g->row = count_row(argv1);
	if (g->row < 0)
		return (0);
	g->arr = readfile(argv1, g->row);
	g->column = ft_strlen(g->arr[0]);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->column * 48, g->row * 48, "mushroom");
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

	if (argc != 2 || !check_arg(argv[1]))
	{
		printf("Error\n");
		return (0);
	}
	ft_bzero(&g, sizeof(g));
	if (init_game(argv[1], &g) == 0)
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
