/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:41:26 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 11:49:32 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	check_scene(void)
{
	if (ft_float_equal(scalar_prod(g_cam.dir, g_cam.screen), 0.0f) == KO)
		ft_errno(SCREEN_CAM, -1, FATAL);
}
