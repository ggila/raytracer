// read_object.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/24 19:24:50 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

void	read_plan(const int fd, union u_o *const u)
{
	read_pos(fd, &(u->plan.point));
	u->plan.normal[W] = 1.0f;
	read_pos(fd, &(u->plan.normal));
	u->plan.normal[W] = 0.0f;
}

