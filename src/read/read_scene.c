/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 07:32:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		read_error(void)
{
	write(1, READ_ERROR, 22);
	exit(KO);
}

static void	setup_cam(const int fd)
{
	char	buf[5];

	if (read(fd, buf, 4) == -1)
		read_error();
	if (ft_strncmp(buf, "cam|", 4))
		read_error();
	read_pos(fd, (void*)g_cam.pos);
	read_pos(fd, (void*)g_cam.dir);
	g_cam.dir[W] = 0.0f;
	if ((read(fd, buf, 2) == -1 ) || ft_strncmp(buf, "\n\n", 2))
		read_error();
}

char		read_map(const char * const str)
{
	int				fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		read_error();
	setup_cam(fd);
	read_objects(fd);
	close(fd);
	return (OK);
}
