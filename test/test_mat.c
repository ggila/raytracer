/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 22:02:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	test_add(void)
{
	printf("testadd\n");
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
	{
		int j = -1;
		while (++j < 4)
			if (j >= i)
				mat2[i][j] = 1;
	}
	print_mat(mat2);
	add(mat, mat, NULL);
	print_mat(mat);
	add(mat, mat2, buf);
	print_mat(buf);
}

void	test_rot(void)
{
	printf("testrot\n");
	t_mat	mat;

//	rot(mat, 3.1415926535/2, 0., 0.);
//	print_mat(mat);
//	rot(mat, 0., 3.1415926535/2, 0.);
//	print_mat(mat);
//	rot(mat, 0., 0., 3.1415926535/2);
//	print_mat(mat);
//	rot(mat, 2.3, 53.3, 10.);
//	print_mat(mat);
	rot(mat, 3.1415926535/2, 3.1415926535/2, 3.1415926535/2);
//	print_mat(mat);
}

int	main(void)
{
	test_rot();
	return(0);
}
