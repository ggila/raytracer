/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:41:26 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 11:49:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	check_scene(void)
{
	if (ft_float_equal(scalar_product(g_cam.dir, g_cam.screen), 0) == KO)
		scene_error();
}
