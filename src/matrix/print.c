// print.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/23 15:54:16 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"
#include <stdio.h>

void	print_mat(t_mat mat)
{
	int	i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%.2f\t", mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
