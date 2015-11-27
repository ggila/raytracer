/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:13:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 09:53:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

char	ft_float_equal(float a, float b)
{
	float diff;
	float largest;
	
	diff = fabs(a - b);
	a = fabs(a);
	b = fabs(b);
	largest = (b > a) ? b : a;
	if (diff <= largest * FLT_EPSILON)
	    return OK;
	return KO;
}
