/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:24:18 by echung            #+#    #+#             */
/*   Updated: 2021/08/08 22:25:05 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
