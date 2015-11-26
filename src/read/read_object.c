/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:24:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 12:57:01 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	check_token(int fd)
{
	int		r;
	char	b;

	r = read(fd, &b, 1);
	if ((r == -1) || (b != '|'))
		read_error();
}

static void	init(void (*f[4])(int, union u_o*))
{
	f[PLAN] = read_plan;
	f[SPHERE] = read_sphere;
	f[CYLINDRE] = read_cylindre;
	f[CONE] = read_cone;
}

static void	read_object(int fd, t_object *obj, int shape,
							void (*f[4])(int, union u_o*))
{
	t_vect	color;

	if (shape > 3)
		read_error();
	obj->type = shape;
	read_pos(fd, &(color));
	obj->color = ((unsigned char)color[0] << 16) +
					((unsigned char)color[1] << 8) +
					(unsigned char)color[2];
	obj->color &= 0X00ffffff;
	f[shape](fd, &(obj->shape));
}

void		read_objects(int fd)
{
	char			b;
	int				r;
	int				i;
	void			(*f[4])(int, union u_o*);

	init(f);
	i = 0;
	while ((r = read(fd, &b, 1)))
	{
		if ((r == -1) || (i == 10) || !ft_isdigit(b))
			read_error();
		check_token(fd);
		read_object(fd, &(g_obj[i]), b - '0', f);
		r = read(fd, &b, 1);
		if ((r == -1) || (b != '\n'))
			read_error();
		i++;
	}
	if (read(fd, &b, 1))
		read_error();
}
