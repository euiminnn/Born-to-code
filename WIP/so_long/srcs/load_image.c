/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:18:35 by echung            #+#    #+#             */
/*   Updated: 2021/08/10 18:23:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_global *g)
{
	int	img_w;
	int	img_h;

	g->back = mlx_xpm_file_to_image(g->mlx, \
			"assets/grass_n_flower-3840.xpm", &img_w, &img_h);
	g->tree = mlx_xpm_file_to_image(g->mlx, \
			"assets/tree_48.xpm", &img_w, &img_h);
	g->img_w1 = mlx_xpm_file_to_image(g->mlx, \
			"assets/mushroom_xpm/walk1.xpm", &img_w, &img_h);
	g->img_w3 = mlx_xpm_file_to_image(g->mlx, \
			"assets/mushroom_xpm/walk3.xpm", &img_w, &img_h);
	g->heart_r = mlx_xpm_file_to_image(g->mlx, \
			"assets/redheart_48_withmargin.xpm", &img_w, &img_h);
	g->portal = mlx_xpm_file_to_image(g->mlx, \
			"assets/portal_48.xpm", &img_w, &img_h);
}
