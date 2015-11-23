/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:14:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/23 12:15:31 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	sincos(void)
{
	int		i;
	double	ang;
	double	inc;

	i = -1;
	ang = 0;
	inc = 2.0 * PI / 3600.0;
	while (++i < 3600)
	{
		g_cos[i] = cos(ang);
		g_sin[i] = sin(ang);
		ang += inc;
	}
}

static int	ft_init_env(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (KO);
	if (!(env->win = mlx_new_window(env->mlx, IM_WIDTH, IM_HEIGHT, TITLE)))
		return (KO);
	if ((env->img.img = mlx_new_image(env->mlx, IM_WIDTH, IM_HEIGHT)))
		env->img.data = mlx_get_data_addr(env->img.img, &(env->img.bpp),
				&(env->img.size_line), &(env->img.endian));
	if (!env->img.img || !env->img.data)
		return (KO);
	sincos();
	return (OK);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (KO);
	if (read_map(av[1]) == KO || ft_init_env(&env) == KO)
		return (KO);
	return (OK);
}
