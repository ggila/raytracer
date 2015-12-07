/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:14:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 09:35:31 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

//static void	init_mlx(void)
void	init_mlx(void)
{
	int	endian;

	if (!(g_env.mlx = mlx_init()))
		exit(KO);
	if (!(g_env.win = mlx_new_window(g_env.mlx, IM_WIDTH, IM_HEIGHT, TITLE)))
		exit(KO);
	if ((g_env.img = mlx_new_image(g_env.mlx, IM_WIDTH, IM_HEIGHT)))
		g_env.data = mlx_get_data_addr(g_env.img, &(g_env.datasize),
				&(g_env.dataline), &(endian));
	if (!g_env.img || !g_env.data)
		exit(KO);
	g_env.datasize /= 8;
}

static void		init_object(void)
{
	int i;

	ft_bzero(g_obj, 11 * sizeof(t_object));
	i = -1;
	while (++i < 11)
		g_obj[i].type = -1;
}

//int			main(void)
int			main(int ac, char **av)
{
	if (ac != 2)
		return (KO);
//	init_mlx();
	init_object();
	read_map(av[1]);
	check_scene();
	raytracer();
	return (OK);
}
