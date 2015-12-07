/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_vect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 07:35:31 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 09:27:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	dot_vect(const float m, t_vect vect, t_vect buf)
{
	float	*res;
	int		i;

	res = (buf == NULL) ? vect : buf;
	i = -1;
	while (++i < 4)
		res[i] = m * vect[i];
}
