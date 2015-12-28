// dot_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/12/07 07:35:31 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	dot_vect(const float m, t_vect vect, t_vect buf)
{
	float	*res;
	int		i;

	res = (buf == NULL) ? vect : buf;
	i = -1;
	while (++i < 4)
		res[i] = m * vect[i];
}
