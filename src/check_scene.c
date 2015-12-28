// check_scene.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/27 11:41:26 by ggilaber
// 2015/12/28 20:06:25 by ggilaber

#include "raytracer.h"

void	check_scene(void)
{
	if (ft_float_equal(scalar_prod(g_cam.dir, g_cam.screen), 0.0f) == KO)
		ft_errno(SCREEN_CAM, -1, FATAL);
}
