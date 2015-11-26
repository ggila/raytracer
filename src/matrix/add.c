/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 21:27:13 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	add(t_mat lhs, const t_mat rhs, t_mat buf)
{
	float	*ret;
	int		i;
	int		j;

	ret = (float*)lhs;
	if (buf != NULL)
	{
		ft_bzero(buf, MAT_SIZE);
		ret = (float*)buf;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			ret[4 * i + j] = lhs[i][j] + rhs[i][j];
	}
	return;
}
