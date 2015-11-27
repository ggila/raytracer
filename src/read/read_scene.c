/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 17:24:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

extern int g_line;

static void	setup_cam(const int fd)
{
	char	buf[5];

	if (read(fd, buf, 4) == -1)
		scene_error(READ, -1);
	if (ft_strncmp(buf, "100|", 4))
		scene_error(CAM_IDENTIFIER, g_line);
	read_pos(fd, (void*)g_cam.pos);
	read_pos(fd, (void*)g_cam.dir);
	g_cam.dir[W] = 0.0f;
	if ((read(fd, buf, 2) == -1 ))
		scene_error(READ, -1);
	if (ft_strncmp(buf, "\n\n", 2))
		scene_error(CAM_END, g_line);
}

char		read_map(const char * const str)
{
	int				fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		scene_error(OPEN, -1);
	setup_cam(fd);
	read_objects(fd);
	close(fd);
	return (OK);
}
