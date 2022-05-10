/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:08:21 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:08:22 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <time.h>

static int	set_camera(t_camera *cam, t_vec lookfrom, t_vec dir, double fov)
{
	double		ratio;

	ratio = m()->scr.wid / m()->scr.hei;
	cam->pos = lookfrom;
	cam->dir = dir;
	cam->view_height = 2.0 * tan((fov * M_PI / 180) / 2.0);
	cam->view_width = ratio * cam->view_height;
	cam->fov = fov;
	cam->w = vec_oppo(cam->dir);
	cam->u = vec_unit(vec_cross(cam->w, vec(0, 1, 0)));
	if (cam->u.x == 0 && cam->u.y == 0 && cam->u.z == 0)
		cam->u = vec_unit(vec_cross(cam->w, vec(0, 0, 1)));
	cam->v = vec_cross(cam->w, cam->u);
	cam->hor = vec_muln(cam->u, cam->view_width);
	cam->ver = vec_muln(cam->v, cam->view_height);
	cam->low_left_corner = vec_cal(\
							(t_vec [4]){lookfrom, cam->hor, cam->ver, cam->w}, \
							(double [4]){1, -0.5, -0.5, -1}, \
							4);
	return (OK);
}

int	add_camera(t_vec lookfrom, t_vec dir, double fov)
{
	t_minirt	*g;

	g = m();
	set_camera(&g->cam, lookfrom, dir, fov);
	g->cam.img = mlx_new_image(g->scr.mlx, g->scr.wid, g->scr.hei);
	g->cam.img_addr = mlx_get_data_addr(g->cam.img, &g->scr.bits_per_pixel, \
										&g->scr.line_length, &g->scr.endian);
	return (OK);
}
