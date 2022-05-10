/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:18:54 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:18:55 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	in_shadow(t_ray *light_ray, double light_len)
{
	t_hit_record	rec;

	light_ray->dir = vec_unit_(&light_ray->dir);
	if (hit_world(m()->wrd, light_ray, (double [2]){EPSILON, light_len}, &rec))
		return (OK);
	return (ERROR);
}

static t_clr	get_specular(t_hit_record *rec, t_light *light, t_vec light_dir)
{
	t_vec			view_dir;
	t_vec			refl_dir;
	double			spec;

	view_dir = vec_unit(vec_oppo(rec->rayin));
	refl_dir = reflect(vec_oppo(light_dir), rec->n);
	spec = pow(ft_max(vec_dot(view_dir, refl_dir), 0.0), KSN);
	return (vec_muln(vec_muln(light->color, KS), spec));
}

static t_clr	get_light_color(t_hit_record *rec, t_light *light)
{
	t_clr			diffuse;
	t_vec			light_dir;
	double			kd;
	t_clr			specular;
	t_ray			light_ray;

	light_ray.dir = vec_cal((t_vec [2]){light->origin, rec->p}, \
							(double [2]){1, -1}, 2);
	light_ray.origin = vec_cal((t_vec [2]){rec->p, rec->n}, \
								(double [2]){1, EPSILON}, 2);
	if (in_shadow(&light_ray, vec_length_(&light_ray.dir)))
		return (vec(0, 0, 0));
	light_dir = vec_unit(light_ray.dir);
	kd = ft_max(vec_dot(rec->n, light_dir), 0.0);
	diffuse = vec_muln(light->color, kd);
	specular = get_specular(rec, light, light_dir);
	return (vec_muln(vec_add(diffuse, specular), light->ratio * LUMEN));
}

t_clr	phong(t_hit_record *rec)
{
	t_clr		color;

	color = (t_clr){0, 0, 0};
	color = vec_add(color, get_light_color(rec, &m()->light));
	color = vec_add(color, vec_muln(m()->ambi.color, m()->ambi.ratio));
	return (vec_min(vec_mul(color, rec->color), vec(1, 1, 1)));
}
