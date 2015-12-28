// print.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/24 09:38:42 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"
#include <stdio.h>

void	print_vect(t_vect vect)
{
	int	i;

	i = -1;
	while (++i < 4)
			printf("%.2f\t", vect[i]);
	printf("\n");
}

void	print_point(t_point point)
{
	printf("%.2f\t%.2f\t%.2f\n",
								point[X],
								point[Y],
								point[Z]);
}
