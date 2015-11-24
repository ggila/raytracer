/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:38:42 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 16:29:30 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

void	print_vect(t_vect *vect)
{
	int	i;

	i = -1;
	while (++i < 4)
			printf("%.2f\t", (*vect)[i]);
	printf("\n\n");
}
