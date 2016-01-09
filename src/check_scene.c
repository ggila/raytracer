#include "raytracer.h"

void	check_scene(void)
{
	if (ft_float_equal(scalar_prod(g_cam.dir, g_cam.screen), 0.0f) == KO)
		ft_errno(SCREEN_CAM, -1, FATAL);
}
