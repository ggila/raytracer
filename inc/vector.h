/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 08:16:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 11:29:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define X 0
# define Y 1
# define Z 2
# define W 3

# define VECT_SIZE (4 * sizeof(float))

typedef float	t_mat[4][4];
typedef float	t_vect[4];
typedef float	t_point[4];

/*
** Proto
*/

/*
** ./src/vector
*/

void	dot_vect(const float m, t_vect vect, t_vect buf);
void	matvect(const t_mat mat, t_vect vect, t_vect buf);
float	norm_vect(const t_vect vect);
void	cross_prod(const t_vect u, const t_vect v, t_vect buf);
void	new_vect(t_vect new, const float x, const float y, const float z);
float	scalar_prod(const t_vect u, const t_vect v);
void	add_vect(t_vect u, const t_vect v, t_vect buf);
void	om_vect(const t_point o, const t_point m, t_vect om);
void	print_vect(t_vect vect);
void	print_point(t_point point);

#endif
