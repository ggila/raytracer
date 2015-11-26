/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:24:26 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 09:13:53 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <string.h>

void		init_step(t_vect step[2])
{
	(void)step;
}

void		raytracer(void)
{
	int		i;
	int		j;
	t_vect	step[2];
	t_ray	ray;


	ft_memcpy(&ray, &g_cam, sizeof(t_ray));
	init_step(step);
	j = -1;
	while (++j < IM_HEIGHT)
	{
		i = -1;
		while (++i < IM_WIDTH)
		{
		}
	}
//	mlx_put_image_to_window(g_env.mlx, g_env.win, g_env.img.img, 0, 0);
}
