/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:24:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 21:26:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	read_plan(int fd, union u_o *u)
{
	u->type = PLAN;
	read_pos(fd, &(u->plan.point));
	read_pos(fd, &(u->plan.normal));
}

void	read_sphere(int fd, union u_o *u)
{
	u->type = SPHERE;
	read_pos(fd, &(u->sphere.center));
	u->sphere.radius = read_float(fd, '|');;
}

void	read_cylindre(int fd, union u_o *u)
{
	u->type = CYLINDRE;
	read_pos(fd, &(u->cylindre.point));
	read_pos(fd, &(u->cylindre.dir));
	u->cylindre.radius = read_float(fd, '|');
}

void	read_cone(int fd, union u_o *u)
{
	u->type = CONE;
	read_pos(fd, &(u->cone.center));
	read_pos(fd, &(u->cone.dir));
	u->cone.ang = read_float(fd, '|');
}
