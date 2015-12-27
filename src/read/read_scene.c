/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 11:48:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

extern int g_line;

static void	setup_cam(const int fd)
{
	char	buf[5];

	if (read(fd, buf, 4) == -1)
		ft_errno(READ, -1, FATAL);
	if (ft_strncmp(buf, "100|", 4))
		ft_errno(CAM_IDENTIFIER, g_line, FATAL);
	read_pos(fd, (void*)g_cam.pos);
	read_pos(fd, (void*)g_cam.dir);
	read_pos(fd, (void*)g_cam.screen);
	g_cam.dir[W] = 0.0f;
	if ((read(fd, buf, 2) == -1 ))
		ft_errno(READ, -1, FATAL);
	if (buf[0] != '\n')
		ft_errno(END_OBJ, g_line, FATAL);
	g_line++;
	if (buf[1] != '\n')
		ft_errno(CAM_END, g_line, FATAL);
}

char		read_map(const char *const str)
{
	int				fd;

	g_line = 1;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_errno(OPEN, -1, FATAL);
	setup_cam(fd);
	read_objects(fd);
	close(fd);
	return (OK);
}
