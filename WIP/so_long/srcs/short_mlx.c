/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:14:50 by echung            #+#    #+#             */
/*   Updated: 2021/08/10 18:42:05 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(t_global *g, void *img, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->win, img, i, j);
}
