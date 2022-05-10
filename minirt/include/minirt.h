/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:30 by ycha              #+#    #+#             */
/*   Updated: 2021/06/15 14:24:30 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# include "vector.h"
# include "library.h"
# include "light.h"
# include "object.h"
# include "parse.h"
# include "event.h"
# include "camera.h"

# define ERROR 0
# define OK 1
# define EPSILON 1e-6

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	wid;
	double	hei;
}		t_screen;

typedef struct s_minirt
{
	t_screen	scr;
	t_world		*wrd;
	t_camera	cam;
	t_light		light;
	t_light		ambi;
	int			num_a;
	int			num_c;
	int			num_l;
}		t_minirt;

t_minirt	*m(void);

#endif
