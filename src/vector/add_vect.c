// add_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/12/07 08:17:01 by ggilaber
// 2015/12/28 20:06:32 by ggilaber


#include "raytracer.h"

void	add_vect(t_vect u, const t_vect v, t_vect buf)
{
	float	*res;
	int		i;

	res = (buf == NULL) ? u : buf;
	if (res == buf)
		ft_bzero(res, VECT_SIZE);
	i = -1;
	while (++i < 3)
		res[i] = u[i] + v[i];
}
