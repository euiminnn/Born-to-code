/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:28 by ycha              #+#    #+#             */
/*   Updated: 2022/04/25 19:44:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	setting(void)
{
	t_minirt	*g;

	g = m();
	g->scr.win = mlx_new_window(\
		g->scr.mlx, g->scr.wid, g->scr.hei, "this is minirt");
	mlx_key_hook(m()->scr.win, key_hook, 0);
	mlx_hook(m()->scr.win, 17, 0, exit_hook, 0);
}

static int	init(void)
{
	ft_memset(m(), 0, sizeof(t_minirt));
	m()->wrd = init_world();
	if (!m()->wrd)
		return (ERROR);
	m()->scr.mlx = mlx_init();
	m()->scr.wid = 800;
	m()->scr.hei = 600;
	return (OK);
}

t_minirt	*m(void)
{
	static t_minirt	mini;

	return (&mini);
}

int	main(int argc, char **argv)
{
	if (!init() || !input(argc, argv))
	{
		printf("Error\n");
		return (ERROR);
	}
	setting();
	render();
	mlx_put_image_to_window(\
					m()->scr.mlx, \
					m()->scr.win, \
					m()->cam.img, 0, 0);
	mlx_loop(m()->scr.mlx);
	return (0);
}
