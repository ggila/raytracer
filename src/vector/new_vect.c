// new_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/24 08:56:32 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	new_vect(t_vect new, const float x, const float y, const float z)
{
	ft_bzero(new, VECT_SIZE);
	new[X] = x;
	new[Y] = y;
	new[Z] = z;
	new[W] = 0.0f;
}
