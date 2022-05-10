/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:18:45 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:18:46 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_light(t_pnt origin, double ratio)
{
	t_minirt	*g;

	g = m();
	g->light.origin = origin;
	g->light.color = vec(1, 1, 1);
	g->light.ratio = ratio;
	return (OK);
}
