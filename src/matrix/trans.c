// trans.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/23 16:52:42 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	trans(const t_vect vect, t_mat mat)
{
	mat[X][W] = vect[X];
	mat[Y][W] = vect[Y];
	mat[Z][W] = vect[Z];
	mat[W][W] = vect[W];
}
