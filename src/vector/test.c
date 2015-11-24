/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 13:47:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	main(void)
{
	t_mat mat;
	t_vect v1;
	t_vect v2;
	t_vect v3;
	int i;

	i = -1;
	ft_bzero(mat, MAT_SIZE);
	while (++i < 4)
	{
		int j = -1;
		while (++j < 4)
			mat[i][j] = i + j;
	}
	new_vect(&v1, 2, 3, 4);
	print_mat(&mat);
	new_vect(&v2, 1, 2, 3);
	print_vect(&v2);
	dot_vect(&mat, &v2, &v3);
	print_vect(&v3);
	dot_vect(&mat, &v2, NULL);
	print_vect(&v2);
	return (OK);
}
