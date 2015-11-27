/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:24:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 07:30:25 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	read_plan(const int fd, union u_o * const u)
{
	read_pos(fd, &(u->plan.point));
	u->plan.normal[W] = 1.0f;
	read_pos(fd, &(u->plan.normal));
	u->plan.normal[W] = 0.0f;
}

void	read_sphere(const int fd, union u_o * const u)
{
	read_pos(fd, &(u->sphere.point));
	u->sphere.point[W] = 1.0f;
	u->sphere.radius = read_float(fd, '|');;
}

void	read_cylindre(const int fd, union u_o * const u)
{
	read_pos(fd, &(u->cylindre.point));
	u->cylindre.point[W] = 1.0f;
	read_pos(fd, &(u->cylindre.dir));
	u->cylindre.dir[W] = 0.0f;
	u->cylindre.radius = read_float(fd, '|');
}

void	read_cone(const int fd, union u_o * const u)
{
	read_pos(fd, &(u->cone.point));
	u->cone.point[W] = 1.0f;
	read_pos(fd, &(u->cone.dir));
	u->cone.dir[W] = 0.0f;
	u->cone.ang = read_float(fd, '|');
}
