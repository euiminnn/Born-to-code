/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:39 by echung            #+#    #+#             */
/*   Updated: 2022/04/23 22:01:35 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	error_in_range(t_vec v, int min, int max)
{
	if (v.x < min || v.x > max)
		return (ERROR);
	if (v.y < min || v.y > max)
		return (ERROR);
	if (v.z < min || v.z > max)
		return (ERROR);
	return (OK);
}

int	parse_pl(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;

	if (!(ft_arrsize(line) == 4)
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[3]))
		return (ERROR);
	if (error_in_range(n, -1, 1) == ERROR)
		return (ERROR);
	if (error_in_range(color, 0, 255) == ERROR)
		return (ERROR);
	if (!add_world(m()->wrd, create_plane(c, n), hit_plane, color))
		return (ERROR);
	return (OK);
}

int	parse_cy(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	r;
	double	h;

	if (!(ft_arrsize(line) == 6)
		|| !ft_atod(&r, line[3])
		|| !ft_atod(&h, line[4])
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[5]))
		return (ERROR);
	if (error_in_range(n, -1, 1) == ERROR)
		return (ERROR);
	if (error_in_range(color, 0, 255) == ERROR)
		return (ERROR);
	if (!add_world(m()->wrd, create_cylinder(c, n, r, h), hit_cylinder, color))
		return (ERROR);
	return (OK);
}
