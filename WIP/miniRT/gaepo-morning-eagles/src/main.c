#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"

int		main(void)
{
	int		i;
	int		j;
/*
	double	r;
	double	g;
	double	b;
	int		canvas_width;
	int		canvas_height;
*/
	t_color3	pixel_color;

	canvas_width = 256;
	canvas_height = 256;

	printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
	j = canvas_height - 1;

	while (j >= 0)
	{
		i = 0;
		while (i < canvas_width)
		{
			/*
			r = (double)i / (canvas_width - 1);
			g = (double)j / (canvas_height - 1);
			b = 0.25;
			printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			*/
			pixel_color.x = (double)i / (canvas_weight - 1);
			pixel_color.y = (double)j / (canvas_height - 1);
			pixel_color.z = 0.25;
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
