/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 22:16:32 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		read_error(void)
{
	write(1, READ_ERROR, 22);
	exit(KO);
}

static void	setup_cam(int fd)
{
	char	buf[10];

	buf[4] = '\0';
	if (read(fd, buf, 4) == -1)
		read_error();
	if (ft_strcmp(buf, "cam|"))
		read_error();
	read_pos(fd, (void*)g_cam.pos);
	read_pos(fd, (void*)g_cam.dir);
	if ((read(fd, buf, 1) == -1 ) || (buf[0] != '\n'))
		read_error();
}

static void		init(void (*f[4])(int, union u_o*))
{
	f[PLAN] = read_plan;
	f[SPHERE] = read_sphere;
	f[CYLINDRE] = read_cylindre;
	f[CONE] = read_cone;
}

static void	read_objects(int fd)
{
	void			(*f[4])(int, union u_o*);
	char			b;
	int				r;
	int				i;

	init(f);
	i = 0;
	while ((r = read(fd, &b, 1)))
	{
		if ((r == -1) || !ft_isdigit(b))
			read_error();
		f[b - '0'](fd, (union u_o*)g_obj + i);
		r = read(fd, &b, 1);
		if ((r == -1) || (b != '\n'))
			read_error();
		i++;
	}
	if (read(fd, &b, 1))
		read_error();
}

char		read_map(char *str)
{
	int				fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		read_error();
	setup_cam(fd);
	read_objects(fd);
	close(fd);
	return (OK);
}
