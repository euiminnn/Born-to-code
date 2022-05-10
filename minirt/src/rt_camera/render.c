/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:08:33 by echung            #+#    #+#             */
/*   Updated: 2022/04/30 19:02:48 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel(int x, int y, int color)
{
	char	*dst;

	if (!m()->cam.img_addr)
		return ;
	if (x < 0 || x >= m()->scr.wid || y < 0 || y >= m()->scr.hei)
		return ;
	dst = m()->cam.img_addr + \
		(y * m()->scr.line_length + x * (m()->scr.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	clamp_color(t_vec colors)
{
	colors.x = clamp(colors.x, 0, 0.999);
	colors.y = clamp(colors.y, 0, 0.999);
	colors.z = clamp(colors.z, 0, 0.999);
	return (trgb(0, colors.x * 256, colors.y * 256, colors.z * 256));
}

static t_clr	ray_color(t_ray *ray)
{
	t_hit_record	rec;
	double			val_for_sky;
	t_vec			ray_from_cam;

	if (hit_world(m()->wrd, ray, (double [2]){0.001, INFINITY}, &rec))
		return (phong(&rec));
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}

static void	render_pixel(int x, int y)
{
	t_ray		ray;
	t_camera	*cam;

	cam = &m()->cam;
	ray.origin = cam->pos;
	ray.dir = vec_cal((t_vec [4]){cam->low_left_corner, \
									cam->hor, \
									cam->ver, \
									cam->pos}, \
					(double [4]){1, x / m()->scr.wid, y / m()->scr.hei, -1}, \
					4);
	ray.dir = vec_unit_(&ray.dir);
	put_pixel(x, y, clamp_color(ray_color(&ray)));
}

void	render(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m()->scr.hei)
	{
		x = -1;
		while (++x < m()->scr.wid)
		{
			render_pixel(x, y);
		}
	}
}
