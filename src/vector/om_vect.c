/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   om_vect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 07:18:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 08:21:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	om_vect(const t_point o, const t_point m, t_vect om)
{
	int	i

	ft_bzero(om, VECT_SIZE);
	i = -1;
	while (++i < 4)
		om[i] = m[i] - o[i];
}
