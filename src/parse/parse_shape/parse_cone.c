// read_object.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/24 19:24:50 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	read_cone(const int fd, union u_o *const u)
{
	read_pos(fd, &(u->cone.point));
	u->cone.point[W] = 1.0f;
	read_pos(fd, &(u->cone.dir));
	u->cone.dir[W] = 0.0f;
	u->cone.ang = read_float(fd, '|');
}
