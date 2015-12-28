// raytracer.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/26 08:24:26 by ggilaber
// 2015/12/28 20:06:18 by ggilaber

#include "raytracer.h"
#include <string.h>

static void	init_screen_dir(t_vect screen_dir[2])
{
	t_vect	oz;

	cross_prod(g_cam.dir, g_cam.screen, oz);
	dot_vect(((float)IM_HEIGHT) / ((float)IM_WIDTH * norm_vect(g_cam.dir))
			, oz, NULL);
	ft_memcpy(screen_dir[0], g_cam.screen, VECT_SIZE);
	ft_memcpy(screen_dir[1], oz, VECT_SIZE);
}

static void	init_pos(t_point screen_pos, t_vect oz)
{
	t_vect	buf;

	ft_memcpy(screen_pos , &g_cam, VECT_SIZE);
	add_vect(screen_pos, g_cam.dir, NULL);
	dot_vect(-0.5, g_cam.screen, buf);
	add_vect(screen_pos, buf, NULL);
	dot_vect(-0.5, oz, buf);
	add_vect(screen_pos, buf, NULL);
}

static void	draw_screen(t_point screen_pos, t_vect screen_dir[2])
{
	t_point	target;
	t_point	target_cpy;
	t_ray	ray;
	int		i;
	int		j;

	ft_memcpy(target, screen_pos, VECT_SIZE);
	ft_memcpy(ray, g_cam_pos, VECT_SIZE)
	j = -1;
	while (++j < IM_HEIGHT)
	{
		add_vect(target, screen_dir[1], NULL);
		ft_memcpy(target_cpy, target, VECT_SIZE);
		i = -1;
		while (++i < IM_WIDTH)
		{
			add_vect(target_cpy, screen_dir[0], NULL);
			om_vect(ray.pos, target_cpy, ray.dir);
//			throw_ray(ray);
			g_env.data[j * g_env.dataline + j] = &ray.color;
		}
	}
}

void		raytracer(void)
{
	t_vect	screen_dir[2];
	t_point	screen_pos;

	init_screen_dir(screen_dir);
	init_pos(screen_pos, screen_dir[1]);
	dot_vect(1.0f / IM_WIDTH, screen_dir[0], NULL);
	dot_vect(1.0f / IM_HEIGHT, screen_dir[1], NULL);
	draw_screen(screen_pos, screen_dir);
	mlx_put_image_to_window(g_env.mlx, g_env.win, g_env.img.img, 0, 0);
}
