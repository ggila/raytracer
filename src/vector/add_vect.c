/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:17:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 09:34:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	add_vect(t_vect u, const t_vect v, t_vect buf)
{
	float	*res;
	int		i;

	res = (buf == NULL) ? u : buf;
	if (res == buf)
		ft_bzero(res, VECT_SIZE);
	i = -1;
	while (++i < 3)
		res[i] = u[i] + v[i];
}
