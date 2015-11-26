/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:24:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 12:34:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	read_plan(int fd, union u_o *u)
{
	read_pos(fd, &(u->plan.point));
	read_pos(fd, &(u->plan.normal));
	u->plan.normal[W] = 1.0f;
}

void	read_sphere(int fd, union u_o *u)
{
	read_pos(fd, &(u->sphere.point));
	u->sphere.radius = read_float(fd, '|');;
}

void	read_cylindre(int fd, union u_o *u)
{
	read_pos(fd, &(u->cylindre.point));
	read_pos(fd, &(u->cylindre.dir));
	u->cylindre.dir[W] = 1.0f;
	u->cylindre.radius = read_float(fd, '|');
}

void	read_cone(int fd, union u_o *u)
{
	read_pos(fd, &(u->cone.point));
	read_pos(fd, &(u->cone.dir));
	u->cone.dir[W] = 1.0f;
	u->cone.ang = read_float(fd, '|');
}