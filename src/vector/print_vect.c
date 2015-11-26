/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:38:42 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 17:04:17 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

void	print_vect(t_vect vect)
{
	int	i;

	i = -1;
	while (++i < 4)
			printf("%.2f\t", vect[i]);
	printf("\n");
}

void	print_point(t_point point)
{
	printf("%.2f\t%.2f\t%.2f\n",
								point[X],
								point[Y],
								point[Z]);
}
