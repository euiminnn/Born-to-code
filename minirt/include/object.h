/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:47:53 by ycha              #+#    #+#             */
/*   Updated: 2022/04/07 21:30:21 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "minirt.h"
# include <stdlib.h>

typedef struct s_sphere
{
	t_pnt	c;
	double	r;
}				t_sphere;

typedef struct s_plane
{
	t_pnt	c;
	t_vec	n;
}				t_plane;

typedef struct s_cylinder
{
	t_vec	c;
	t_vec	n;
	double	r;
	double	h;
	t_vec	top;
	t_vec	bot;
}				t_cylinder;

typedef union u_object
{
	t_cylinder	cylinder;
	t_sphere	sphere;
	t_plane		plane;
}		t_object;

typedef struct s_hit_record
{
	t_vec				p;
	t_vec				n;
	t_vec				rayin;
	double				t;
	int					front_face;
	t_clr				color;
}				t_hit_record;

typedef struct s_world
{
	t_object			obj;
	t_clr				color;
	int					(*hit)(struct s_world *this, t_ray *ray, \
									double minmax[2], t_hit_record *out);
	struct s_world		*next;
}				t_world;

t_world		*init_world(void);
int			add_world(t_world *head, t_object obj, \
						int (*hit)(t_world *this, t_ray *ray, \
							double minmax[2], t_hit_record *out), \
									t_clr color);
int			hit_world(t_world *head, t_ray *ray, \
										double minmax[2], t_hit_record *out);
void		set_rec(t_world *this, t_ray *ray, t_hit_record *rec);

t_object	create_sphere(t_vec c, double r);
int			hit_sphere(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);

t_object	create_plane(t_pnt c, t_vec n);
int			hit_plane(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);
int			_get_plane_t(t_vec *v[2], t_ray *ray, \
										double minmax[2], double *t);
void		get_plane_uv(t_hit_record *rec, t_pnt c, double size);

t_object	create_cylinder(t_pnt c, t_vec n, double r, double h);
int			hit_cylinder(t_world *this, t_ray *ray, \
									double minmax[2], t_hit_record *rec);

#endif
