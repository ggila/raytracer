// norm_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/25 11:26:54 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

float	norm_vect(const t_vect vect)
{
	float	norm;

	norm = pow(vect[X], 2.0f)
			+ pow(vect[Y], 2.0f)
			+ pow(vect[Z], 2.0f);
	norm = pow(norm, 0.5f);
	return (norm);
}
