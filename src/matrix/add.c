/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/23 19:04:17 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void add(t_mat *lhs, t_mat *rhs, t_mat *buf)
{
	t_mat	*ret;
	int		i;
	int		j;

	ret = (buf != NULL) ? buf : lhs;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j)
			(*ret)[i][j] = (*lhs)[i][j] + (*rhs)[i][j];
	}
	return;
}
