#include "trace.h"

t_color3    phong_lighting(t_scene *scene)
{
    t_color3    light_color;
    t_object    *lights;

    light_color = color3(0, 0, 0);
    lights = scene->light;
    // while (lights)
    // {
    //     if (lights->type == LIGHT_POINT)
    //         light_color = vplus(light_color, point_light_get(scene, lights->element));
    //     lights = lights->next;
    // }
    light_color = vplus(light_color, scene->ambient);
    return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}