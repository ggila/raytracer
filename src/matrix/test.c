/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/23 20:29:18 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int main(void)
{
	t_mat mat;
	t_mat mat2;
	int i = -1;

	while (++i < 4)
	{
		int j = -1;
		while (++j < 4)
			mat[i][j] = i + j;
	}
	print_mat(mat);
	rot(&mat2, PI / 3, 0, 0);
	print_mat(mat2);
	rot(&mat2, 0, PI / 3, 0);
	print_mat(mat2);
	rot(&mat2, PI / 2, PI, 0);
	print_mat(mat2);
	return (OK);
}
