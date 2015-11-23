/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:16:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/23 09:56:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <math.h>
# include "mlx_encoding.h"
# include "mlx.h"
# include "proto.h"

# define OK 0
# define KO 1

# define TITLE "ggilaber"

# define PI 3.1416

# define IM_WIDTH 600
# define IM_HEIGHT 400

# define X 0
# define Y 1
# define Z 2

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

typedef struct	s_mat
{
	double		mat[16];
}				t_mat;

typedef struct		s_vect3
{
	double	x;
	double	y;
	double	z;
	double	w;
}					t_vect3;

double			g_cos[3600];
double			g_sin[3600];

#endif
