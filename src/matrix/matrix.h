//  matrix.h
//  ggilaber <ggilaber@student.42.fr>
//  2015/11/23 08:16:01 by ggilaber
//  2015/12/07 11:29:52 by ggilaber

#ifndef MATRIX_H
# define MATRIX_H

# define X 0
# define Y 1
# define Z 2
# define W 3

# define MAT_SIZE (16 * sizeof(float))

typedef float	t_mat[4][4];

/*
** Proto
*/

/*
** ./src/matrix
*/

void	trans(const t_vect vect, t_mat mat);
void	dot_mat(t_mat lhs, t_mat rhs, t_mat buf);
void	rot(t_mat ret, const float alpha, const float beta, const float gamma);
void	print_mat(t_mat mat);
void	add(t_mat lhs, const t_mat rhs, t_mat buf);

#endif
