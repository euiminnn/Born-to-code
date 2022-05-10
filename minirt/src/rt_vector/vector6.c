/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:19:30 by echung            #+#    #+#             */
/*   Updated: 2022/03/06 23:19:32 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_length_squared_(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

double	vec_length_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_length_(t_vec *vec)
{
	double	len;

	len = vec_length_squared_(vec);
	len = sqrt(len);
	return (len);
}

double	vec_length(t_vec vec)
{
	double	len;

	len = vec_length_squared_(&vec);
	len = sqrt(len);
	return (len);
}
