/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/08/07 22:53:28 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17 // exit key code

// Mac key code example
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

// x,y and str are meaningless variables.

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

void	param_init(t_param *param)
{
	param->x = start_x;
	param->y = start_y;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

void	edit_map(int param_x, int param_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (arr[i][j] == '1')
				mlx_put_image_to_window(mlx, win, tree, 48 * j, 48 * i);
			if (arr[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, heart_r, 48 * j, 48 * i);
			if (arr[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, portal, 48 * j, 48 * i);
			j++;
		}
		i++;
	}
	if ((param_x / 48) % 2 == 0)
		mlx_put_image_to_window(mlx, win, img_w1, param_x, param_y);
	else
		mlx_put_image_to_window(mlx, win, img_w3, param_x, param_y);
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
	if (keycode == KEY_W || keycode == KEY_S) // Action when W key pressed
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
	else if (keycode == KEY_ESC) // Quit the program when ESC key pressed
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

void	init_map(t_iter it)
{
	mlx_put_image_to_window(mlx, win, back, 0, 0);
	it.i = -1;
	while ((it.i)++ < row - 1)
	{
		it.j = -1;
		while ((it.j)++ < column - 1)
		{
			if (arr[it.i][it.j] == '1')
				mlx_put_image_to_window(mlx, win, tree, 48 * it.j, 48 * it.i);
			if (arr[it.i][it.j] == 'C')
			{
				mlx_put_image_to_window(mlx, \
						win, heart_r, 48 * it.j, 48 * it.i);
				collectibles++;
			}
			if (arr[it.i][it.j] == 'E')
				mlx_put_image_to_window(mlx, win, portal, 48 * it.j, 48 * it.i);
			if (arr[it.i][it.j] == 'P')
			{
				mlx_put_image_to_window(mlx, win, img_w1, 48 * it.j, 48 * it.i);
				start_x = 48 * it.j;
				start_y = 48 * it.i;
			}
		}
	}
}

void	get_image(void)
{
	int	img_w;
	int	img_h;

	back = mlx_xpm_file_to_image(mlx, \
			"../textures/grass_n_flower-3840.xpm", &img_w, &img_h);
	tree = mlx_xpm_file_to_image(mlx, \
			"../textures/tree_48.xpm", &img_w, &img_h);
	img_w1 = mlx_xpm_file_to_image(mlx, \
			"../textures/mushroom_xpm/walk1.xpm", &img_w, &img_h);
	img_w3 = mlx_xpm_file_to_image(mlx, \
			"../textures/mushroom_xpm/walk3.xpm", &img_w, &img_h);
	heart_r = mlx_xpm_file_to_image(mlx, \
			"../textures/redheart_48_withmargin.xpm", &img_w, &img_h);
	portal = mlx_xpm_file_to_image(mlx, \
			"../textures/portal_48.xpm", &img_w, &img_h);
}

int	main(void)
{
	t_iter	iter;

	ft_bzero(&iter, sizeof(t_iter));
	// initiation
	mlx = mlx_init();
	// open window
	win = mlx_new_window(mlx, 480, 480, "mushroom");
	// key press
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, 0);
	// add image
	get_image();
	row = count_gnl("map.ber");
	arr = readfile("map.ber", row);
	column = ft_strlen(arr[0]);
	heart = 0;
	init_map(iter);
	param_init(&param);
	if (parse_map(arr, row, column))
		mlx_loop(mlx);
	else
		printf("🚫 Error: invalid map\n");
	free(arr);
}
