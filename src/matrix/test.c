/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 12:20:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	main(void)
{
	t_mat mat;
	t_mat mat2;
	t_mat buf;
	int i;

	i = -1;
	ft_bzero(mat, MAT_SIZE);
	ft_bzero(mat2, MAT_SIZE);
	while (++i < 4)
	{
		int j = -1;
		while (++j < 4)
			mat[i][j] = i + j;
	}
	print_mat(mat);
	i = -1;
	while (++i < 4)
		mat2[i][i] = 1;
	print_mat(mat2);
	add(&mat, &mat, NULL);
	print_mat(mat);
	add(&mat, &mat2, &buf);
	print_mat(buf);
	return (OK);
}
