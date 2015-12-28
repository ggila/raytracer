// om_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/12/07 07:18:20 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	om_vect(const t_point o, const t_point m, t_vect om)
{
	int	i

	ft_bzero(om, VECT_SIZE);
	i = -1;
	while (++i < 4)
		om[i] = m[i] - o[i];
}
