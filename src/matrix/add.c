/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 12:18:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	add(t_mat *lhs, t_mat *rhs, t_mat *buf)
{
	t_mat	*ret;
	int		i;
	int		j;

	ret = lhs;
	if (buf != NULL)
	{
		ft_bzero(buf, MAT_SIZE);
		ret = buf;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			(*ret)[i][j] = (*lhs)[i][j] + (*rhs)[i][j];
	}
	return;
}
