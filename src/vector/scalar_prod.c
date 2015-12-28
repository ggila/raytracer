// scalar_prod.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/26 09:23:34 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

float	scalar_prod(const t_vect u, const t_vect v)
{
	return (u[X] * v[X] +
			u[Y] * v[Y] +
			u[Z] * v[Z]);
}
