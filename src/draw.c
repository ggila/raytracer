/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:01:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/25 20:27:24 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <string.h>

void		draw(void)
{
	int		i;
	int		j;
	int		color = 0x00FF0000;

	j = -1;
	while (++j < IM_HEIGHT)
	{
		i = -1;
		while (++i < IM_WIDTH)
			mlx_pixel_put(g_env.mlx, g_env.win, i, j, color);
//			memcpy((g_env.img.data + (g_env.img.bpp / 8) *
//					(i + j * IM_WIDTH)), &color, g_env.img.bpp / 8);
	}
	printf("%d\t%d", i, j);
//	mlx_put_image_to_window(g_env.mlx, g_env.win, g_env.img.img, 0, 0);
}