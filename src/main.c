/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:14:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 19:33:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static int	init_mlx(void)
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
	return (OK);
}

static int	init_object(void)
{
	int i;

	ft_bzero(g_obj, 10 * sizeof(u_object));
	i = -1;
	while (++i < 10)
		g_obj[i].type = -1;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (KO);
	if (read_map(av[1]) == KO || init_mlx() == KO)
		return (KO);
	init_object();
	return (OK);
}
