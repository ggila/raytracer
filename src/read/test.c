/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:12:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 22:13:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	print_test(void)
{
	printf("cam:\n%.2f\t%.2f\t%.2f\n", g_cam.pos[X],
			g_cam.pos[Y], g_cam.pos[Z]);
	print_vect(&(g_cam.dir));
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (KO);
	read_map(av[1]);
	print_test();
	return (OK);
}
