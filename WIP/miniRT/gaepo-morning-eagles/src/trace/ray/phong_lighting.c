#include "trace.h"

t_vec3      reflect(t_vec3 v, t_vec3 n)
{
    return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_color3    point_light_get(t_scene *scene, t_light *light)
{
    t_color3    diffuse;
    t_vec3      light_dir;
    double      kd;
    
    t_color3    specular;
    t_vec3      view_dir;
    t_vec3      reflect_dir;
    double      spec;
    double      ksn;
    double      ks;

    double      brightness;

    light_dir = vunit(vminus(light->origin, scene->rec.p));
    kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
    diffuse = vmult(light->light_color, kd);
    
    view_dir = vunit(vmult(scene->ray.dir, -1));
    reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
    ksn = 64;
    ks = 0.5;
    spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
    specular = vmult(vmult(light->light_color, ks), spec);

    brightness = light->bright_ratio * LUMEN;
    return (vmult(vplus(vplus(scene->ambient, diffuse), specular), brightness));
}

t_color3    phong_lighting(t_scene *scene)
{
    t_color3    light_color;
    t_object    *lights;

    light_color = color3(0, 0, 0);
    lights = scene->light;
    while (lights)
    {
        if (lights->type == LIGHT_POINT)
            light_color = vplus(light_color, point_light_get(scene, lights->element));
        lights = lights->next;
    }
    light_color = vplus(light_color, scene->ambient);
    return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}