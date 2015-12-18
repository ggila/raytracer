/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:16:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 11:29:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# include "minilibx.h"
# include "error.h"
# include "matrix.h"
# include "vector.h"

#				include "stdio.h"

# define OK 0
# define KO 1

# define PI 3.1415926535
# define FLT_EPSILON 1.1920929e-07f

//# define SCREEN_WIDTH 4.0
//# define SCREEN_HEIGHT 400

# define PLAN 0
# define SPHERE 1
# define CYLINDRE 2
# define CONE 3

# define ABS(n) (((n) > 0) ? (n) : -(n))

# define MASK			1U

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			datasize;
	int			dataline;
}				t_env;

typedef struct	s_ray
{
	t_point		pos;
	t_vect		vect;
	int			color;
}				t_ray;

typedef struct	s_camera
{
	t_point		pos;
	t_vect		dir;
	t_vect		screen;
}				t_camera;

typedef struct	s_plan
{
	t_point		point;
	t_vect		normal;
}				t_plan;

typedef struct	s_sphere
{
	t_point		point;
	float		radius;
}				t_sphere;

typedef struct	s_cylindre
{
	t_point		point;
	t_vect		dir;
	float		radius;
}				t_cylindre;

typedef struct	s_cone
{
	t_point		point;
	t_vect		dir;
	float		ang;
}				t_cone;

union			u_o
{
	t_plan		plan;
	t_sphere	sphere;
	t_cylindre	cylindre;
	t_cone		cone;
};

typedef struct	s_object
{
	int			type;
	union u_o	shape;
	int			color;
	t_mat		in;
	t_mat		out;
}				t_object;

t_camera		g_cam;
t_object		g_obj[11];
t_env			g_env;

/*
** Proto
*/

/*
** ./src
*/

void	init_errno(void);
void	init_mlx(void);
void	check_scene(void);
void	raytracer(void);

/*
** ./src/lib
*/

void	ft_bzero(void *dst, size_t n);
char	ft_float_equal(float a, float b);
void	ft_errno(int type, int line, char flag);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
void	ft_fill_buf(int n, char *str);
void	ft_putnbr(int n);
void	ft_memcpy(void *dst, void *src, size_t n);

/*
** ./src/read
*/

char	read_map(const char * const str);
int		read_one(int fd, char *b);
void	read_objects(const int fd);
int		read_number(const int fd, const char end, int *n, char *flag);
float	read_float(const int fd, const char end);
void	read_pos(const int fd, const void *addr);
void	read_plan(const int fd, union u_o *const u);
void	read_sphere(const int fd, union u_o *const u);
void	read_cylindre(const int fd, union u_o *const u);
void	read_cone(const int fd, union u_o *const u);

#endif
