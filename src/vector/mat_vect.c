// dot_vect.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/24 09:05:08 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	matvect(const t_mat mat, t_vect vect, t_vect buf)
{
	t_vect	tmp;
	float	*res;
	int		i;
	int		j;

	res = (buf == NULL) ? tmp : buf;
	ft_bzero(res, VECT_SIZE);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res[i] += mat[i][j] * vect[j];
	}
	if (buf == NULL)
		ft_memcpy(vect, res, VECT_SIZE);
}
