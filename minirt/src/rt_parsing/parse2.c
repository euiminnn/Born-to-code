/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:48 by echung            #+#    #+#             */
/*   Updated: 2022/04/23 21:43:28 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sp(char **line)
{
	t_vec	c;
	t_vec	color;
	double	r;

	if (!(ft_arrsize(line) == 4)
		|| !ft_atod(&r, line[2])
		|| !parse_split(&c, line[1])
		|| !parse_split(&color, line[3]))
		return (ERROR);
	if (color.x < 0 || color.x > 255)
		return (ERROR);
	if (color.y < 0 || color.y > 255)
		return (ERROR);
	if (color.z < 0 || color.z > 255)
		return (ERROR);
	if (!add_world(m()->wrd, create_sphere(c, r), hit_sphere, color))
		return (ERROR);
	return (OK);
}
