// cross_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/27 07:44:23 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	cross_prod(const t_vect u, const t_vect v, t_vect buf)
{
	buf[X] = u[Y] * v[Z] - u[Z] * v[Y];
	buf[Y] = u[Z] * v[X] - u[X] * v[Z];
	buf[Z] = u[X] * v[Y] - u[Y] * v[X];
}
