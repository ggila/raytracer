/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:12:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 12:51:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

void	print_camera(void)
{
	printf("cam:\n");
	print_point(&(g_cam.pos));
	print_vect(&(g_cam.dir));
	printf("\n");
}

void	print_plan(union u_o *p)
{
	print_point(&(p->plan.point));
	print_vect(&(p->plan.normal));
	printf("\n");
}

void	print_sphere(union u_o *s)
{
	print_point(&(s->sphere.point));
	printf("%.2f\n", s->sphere.radius);
	printf("\n");
}

void	print_cylindre(union u_o *c)
{
	print_point(&(c->cylindre.point));
	print_vect(&(c->cylindre.dir));
	printf("%.2f\n", c->cylindre.radius);
	printf("\n");
}

void	print_cone(union u_o *c)
{
	print_point(&(c->cone.point));
	print_vect(&(c->cone.dir));
	printf("%.2f\n", c->cone.ang);
	printf("\n");
}

static void	init_object(void)
{
	int i;

	ft_bzero(g_obj, 11 * sizeof(t_object));
	i = -1;
	while (++i < 11)
		g_obj[i].type = -1;
}

//int	main(int ac, char **av)
int	main(void)
{
	void (*f[4])(union u_o*) = {
	print_plan,
	print_sphere,
	print_cylindre,
	print_cone};
	char *tab[] = {"plan", "sphere", "cylindre", "cone"};

//	if (ac != 2)
//		return (KO);

	init_object();

//	read_map(av[1]);
	read_map("./scene/scene_test");
	print_camera();
	int i = -1;
	while (g_obj[++i].type != -1)
	{
		printf("%s:\n0x%x\n", tab[g_obj[i].type], g_obj[i].color);
		f[g_obj[i].type](&(g_obj[i].shape));
	}
	return (OK);
}
