/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:44:23 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 10:19:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	cross_prod(t_vect u, t_vect v, t_vect buf)
{
	buf[X] = u[Y] * v[Z] - u[Z] * v[Y];
	buf[Y] = u[Z] * v[X] - u[X] * v[Z];
	buf[Z] = u[X] * v[Y] - u[Y] * v[X];
}
