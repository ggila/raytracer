/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:42 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 21:40:40 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	trans(const t_vect vect, t_mat mat)
{
	mat[X][W] = vect[X];
	mat[Y][W] = vect[Y];
	mat[Z][W] = vect[Z];
	mat[W][W] = vect[W];
}
