#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

int		main(void)
{
	int		i;
	int		j;
	double	u;
	double	v;
/*
	double	r;
	double	g;
	double	b;
	int		canvas_width;
	int		canvas_height;
*/
	t_color3	pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));

	canvas_width = 256;
	canvas_height = 256;

	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canvas_height - 1;

	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			/*
			r = (double)i / (canvas_width - 1);
			g = (double)j / (canvas_height - 1);
			b = 0.25;
			printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			*/
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray);
			/*
			pixel_color.x = (double)i / (canvas_weight - 1);
			pixel_color.y = (double)j / (canvas_height - 1);
			pixel_color.z = 0.25;
			*/
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
