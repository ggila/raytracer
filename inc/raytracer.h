/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:16:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 22:16:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

#				include "stdio.h"

# define OK 0
# define KO 1

# define TITLE "ggilaber"
# define READ_ERROR "can't read this scene\n"

# define PI 3.1416

# define IM_WIDTH 600
# define IM_HEIGHT 400

# define X 0
# define Y 1
# define Z 2
# define W 3

# define PLAN 0
# define SPHERE 1
# define CYLINDRE 2
# define CONE 3

# define MAT_SIZE (16 * sizeof(float))
# define VECT_SIZE (4 * sizeof(float))

# define ABS(n) (((n) > 0) ? (n) : -(n))

# define MASK			1U

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			bypp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
}				t_env;

typedef float	t_mat[4][4];
typedef float	t_vect[4];
typedef float	t_point[3];

typedef struct	s_camera
{
	t_point		pos;
	t_vect		dir;
}				t_camera;

typedef struct	s_sphere
{
	t_point		center;
	float		radius;
}				t_sphere;

typedef struct	s_plan
{
	t_point		point;
	t_vect		normal;
}				t_plan;

typedef struct	s_cylindre
{
	t_point		point;
	t_vect		dir;
	float		radius;
}				t_cylindre;

typedef struct	s_cone
{
	t_point		center;
	t_vect		dir;
	float		ang;
}				t_cone;

union			u_o
{
	char		type;
	t_plan		plan;
	t_sphere	sphere;
	t_cylindre	cylindre;
	t_cone		cone;
};

t_camera		g_cam;
union u_o		g_obj[10];
t_env			g_env;

# include "proto.h"

#endif
