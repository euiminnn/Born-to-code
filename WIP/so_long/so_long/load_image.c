/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:18:35 by echung            #+#    #+#             */
/*   Updated: 2021/08/08 22:20:02 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(void)
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
