#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere    *sphere(t_point3 center, double radius);
t_object    *object(t_object_type type, void *element);

#endif
