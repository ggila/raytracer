/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:26:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 17:04:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

float	norm_vect(const t_vect vect)
{
	float	norm;

	norm = pow(vect[X], 2.0f)
			+ pow(vect[Y], 2.0f)
			+ pow(vect[Z], 2.0f);
	norm = pow(norm, 0.5f);
	return (norm);
}
