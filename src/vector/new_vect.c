/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:56:32 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 09:38:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	new_vect(t_vect *new, float x, float y, float z)
{
	ft_bzero(new, VECT_SIZE);
	(*new)[X] = x;
	(*new)[Y] = y;
	(*new)[Z] = z;
	(*new)[W] = 1.0f;
}
