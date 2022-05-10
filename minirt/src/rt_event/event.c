/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:08:05 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:08:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(m()->scr.mlx, m()->scr.win);
		exit(0);
	}
	return (0);
}
