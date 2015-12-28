// rot.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/23 15:59:18 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

static void	rotalpha(const float alpha, t_mat mat)
{
	ft_bzero(mat, MAT_SIZE);
	mat[X][X] = 1.0f;
	mat[Y][Y] = cosf(alpha);
	mat[Y][Z] = -sinf(alpha);
	mat[Z][Y] = sinf(alpha);
	mat[Z][Z] = cosf(alpha);
	mat[W][W] = 1.0f;
}

static void	rotbeta(const float beta, t_mat mat)
{
	ft_bzero(mat, MAT_SIZE);
	mat[Y][Y] = 1.0f;
	mat[X][X] = cosf(beta);
	mat[Z][X] = -sinf(beta);
	mat[X][Z] = sinf(beta);
	mat[Z][Z] = cosf(beta);
	mat[W][W] = 1.0f;
}

static void	rotgamma(const float gamma, t_mat mat)
{
	ft_bzero(mat, MAT_SIZE);
	mat[Z][Z] = 1.0f;
	mat[X][X] = cosf(gamma);
	mat[X][Y] = -sinf(gamma);
	mat[Y][X] = sinf(gamma);
	mat[Y][Y] = cosf(gamma);
	mat[W][W] = 1.0f;
}

void		rot(t_mat ret, const float alpha, const float beta, const float gamma)
{
	t_mat	tmp;
	t_mat	matalpha;
	t_mat	matbeta;
	t_mat	matgamma;

	ft_bzero(tmp, MAT_SIZE);
	ft_bzero(ret, MAT_SIZE);
	rotalpha(alpha, matalpha);
	rotbeta(beta, matbeta);
	rotgamma(gamma, matgamma);
	print_mat(matalpha);
	dot_mat(matalpha, matbeta, tmp);
	print_mat(tmp);
	dot_mat(tmp, matgamma, ret);
	print_mat(ret);
}
