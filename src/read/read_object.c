/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:24:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 10:59:21 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			g_line;

int			read_one(int fd, char *b)
{
	int r;

	r = read(fd, b, 1);
	if (r == -1)
		ft_errno(READ, -1, FATAL);
	return (r);
}

static void	check_token(const int fd)
{
	char	b;
	int		r;

	r = read_one(fd, &b);
	if (b != '|' || !r)
		ft_errno(MISSING_TOKEN, g_line, FATAL);
}

static void	init(void (*f[4])(const int, union u_o*))
{
	f[PLAN] = read_plan;
	f[SPHERE] = read_sphere;
	f[CYLINDRE] = read_cylindre;
	f[CONE] = read_cone;
}

static void	read_object(const int fd, t_object *obj, const int shape,
							void (*f[4])(const int, union u_o*))
{
	t_vect	color;

	if (shape < 0 || shape > 3)
		ft_errno(UKNOWN_SHAPE, g_line, FATAL);
	obj->type = shape;
	read_pos(fd, &(color));
	obj->color = ((unsigned char)color[0] << 16) +
					((unsigned char)color[1] << 8) +
					(unsigned char)color[2];
	obj->color &= 0X00ffffff;
	f[shape](fd, &(obj->shape));
}

void		read_objects(const int fd)
{
	char			b;
	int				r;
	void			(*f[4])(int, union u_o*);

	init(f);
	g_line = 3;
	while ((r = read_one(fd, &b)))
	{
		if (g_line == 13)
			ft_errno(NB_OBJECT, g_line, FATAL);
		check_token(fd);
		read_object(fd, &(g_obj[g_line - 3]), b - '0', f);
		r = read_one(fd, &b);
		if (b != '\n')
			ft_errno(END_OBJ, g_line, FATAL);
		g_line++;
	}
}
