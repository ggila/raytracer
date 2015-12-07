/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:23:42 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/07 09:26:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*
** src
*/

void	check_scene(void);
void	init_errno(void);
void	init_mlx(void);
void	raytracer(void);

/*
** src/lib
*/

void	ft_fill_buf(int n, char *str);
void	ft_putnbr(int n);
void	ft_errno(int type, int line, char flag);
void	ft_memcpy(void *dst, void *src, size_t n);
void	ft_bzero(void *dst, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
char	ft_float_equal(float a, float b);

/*
** src/vector
*/

void	matvect(const t_mat mat, t_vect vect, t_vect buf);
void	new_vect(t_vect new, const float x, const float y, const float z);
float	scalar_prod(const t_vect u, const t_vect v);
void	dot_vect(const float m, t_vect vect, t_vect buf);
void	om_vect(const t_point o, const t_point m, t_vect om);
float	norm_vect(const t_vect vect);
void	cross_prod(const t_vect u, const t_vect v, t_vect buf);
void	add_vect(t_vect u, const t_vect v, t_vect buf);
void	print_vect(t_vect vect);
void	print_point(t_point point);

/*
** src/matrix
*/

void	add(t_mat lhs, const t_mat rhs, t_mat buf);
void	dot_mat(t_mat lhs, t_mat rhs, t_mat buf);
void	print_mat(t_mat mat);
void	trans(const t_vect vect, t_mat mat);
void	rot(t_mat ret, const float alpha, const float beta, const float gamma);

/*
** src/read
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
