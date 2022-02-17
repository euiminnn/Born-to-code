#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;
typedef struct s_ray t_ray;
typedef struct s_camera t_camera;

struct s_vec3
{
    double x;
    double y;
    double z;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};
#endif
