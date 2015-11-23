/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:42:15 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/23 19:13:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static float	matrix_dot(t_mat *lhs, t_mat *rhs, int i, int j)
{
	int		l;
	float	ret;

	ret = 0;
	l = -1;
	while (++l < 4)
		ret += (*lhs)[i][l] * (*rhs)[l][j];
	return ret;
}

void			dot(t_mat *lhs, t_mat *rhs, t_mat *buf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j)
			(*buf)[i][j] = matrix_dot(lhs, rhs, i, j);
	}
	return;
}
