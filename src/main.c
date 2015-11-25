/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:14:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/25 19:39:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static int	init_mlx(void)
{
	if (!(g_env.mlx = mlx_init()))
		return (KO);
	if (!(g_env.win = mlx_new_window(g_env.mlx, IM_WIDTH, IM_HEIGHT, TITLE)))
		return (KO);
	if ((g_env.img.img = mlx_new_image(g_env.mlx, IM_WIDTH, IM_HEIGHT)))
		g_env.img.data = mlx_get_data_addr(g_env.img.img, &(g_env.img.bpp),
				&(g_env.img.size_line), &(g_env.img.endian));
	if (!g_env.img.img || !g_env.img.data)
		return (KO);
	return (OK);
}

static void	init_object(void)
{
	int i;

	ft_bzero(g_obj, 11 * sizeof(t_object));
	i = -1;
	while (++i < 11)
		g_obj[i].type = -1;
}

#include <unistd.h>

int			main(int ac, char **av)
{
	if (ac != 2)
		return (KO);
	if (read_map(av[1]) == KO || init_mlx() == KO)
		return (KO);
	init_object();
	draw();
	sleep(5);
	return (OK);
}
