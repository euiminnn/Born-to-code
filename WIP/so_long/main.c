/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/08/09 21:41:14 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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
typedef struct s_global{
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
}	t_global;
*/

void	param_init(t_param *param)
{
	param->x = start_x;
	param->y = start_y;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

void	end_game(void)
{
	if (arr[param.y / 48][param.x / 48] == 'E' && heart == collectibles)
	{
		free(arr);
		exit(0);
	}
}

void	get_collectibles(void)
{
	if (arr[param.y / 48][param.x / 48] == 'C')
	{
		heart++;
		arr[param.y / 48][param.x / 48] = '0';
	}
}

int	key_press(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S)
	{
		param.y -= ((keycode == KEY_W) - (keycode == KEY_S)) * 48;
		if (arr[param.y / 48][param.x / 48] == '1')
			param.y += ((keycode == KEY_W) - (keycode == KEY_S)) * 48;
	}
	else if (keycode == KEY_D || keycode == KEY_A)
	{
		param.x += ((keycode == KEY_D) - (keycode == KEY_A)) * 48;
		if (arr[param.y / 48][param.x / 48] == '1')
			param.x -= ((keycode == KEY_D) - (keycode == KEY_A)) * 48;
	}
	else if (keycode == KEY_ESC)
	{
		free(arr);
		exit(0);
	}
	get_collectibles();
	mlx_put_image_to_window(mlx, win, back, 0, 0);
	edit_map(param.x, param.y);
	end_game();
	return (0);
}

int	main(void)
{
	t_iter	iter;
	t_global	g;

	ft_bzero(&iter, sizeof(t_iter));
	ft_bzero(&g, sizeof(g));
	g.mlx = mlx_init();
	g.win = mlx_new_window(mlx, 480, 480, "mushroom");
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &key_press, 0);
	load_image();
	g.row = count_gnl("map.ber");
	g.arr = readfile("map.ber", row);
	g.column = ft_strlen(arr[0]);
	g.heart = 0;
	init_map(iter);
	param_init(&param);
	if (parse_map(g.arr, g.row, g.column))
		mlx_loop(g.mlx);
	else
		printf("🚫 Error: invalid map\n");
	free(g.arr);
}
