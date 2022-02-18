#include "trace.h"

void    set_face_normal(t_ray *r, t_hit_record *rec)
{
    rec->front_face = vdot(r->dir, rec->normal) < 0;
    rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}