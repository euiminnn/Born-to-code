/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:09:28 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:09:52 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*init_world(void)
{
	t_world	*head;

	head = (t_world *)malloc(sizeof(t_world));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int	add_world(t_world *head, t_object obj, \
	int (*hit)(t_world *this, t_ray *ray, double minmax[2], t_hit_record *out), \
	t_clr color)
{
	t_world	*new;

	new = (t_world *)malloc(sizeof(t_world) * 1);
	if (!new)
		return (ERROR);
	new->obj = obj;
	new->hit = hit;
	new->color = vec_divn(color, 255);
	new->next = head->next;
	head->next = new;
	return (OK);
}

int	hit_world(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out)
{
	t_hit_record	temp_rec;
	t_world			*w;
	int				flag;

	flag = 0;
	w = head;
	while (w->next)
	{
		w = w->next;
		if (w->hit(w, ray, minmax, &temp_rec))
		{
			minmax[1] = temp_rec.t;
			*out = temp_rec;
			flag = 1;
		}
	}
	return (flag);
}

void	set_rec(t_world *this, t_ray *ray, t_hit_record *rec)
{
	rec->rayin = ray->dir;
	rec->front_face = vec_dot_(&ray->dir, &rec->n) < 0;
	if (!rec->front_face)
		rec->n = vec_oppo(rec->n);
	rec->color = this->color;
}
