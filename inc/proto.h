/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:01:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 12:02:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*
** src
*/

void	init_step(t_vect step[2]);
void	raytracer(void);

/*
** src/lib
*/

void	ft_memcpy(void *dst, void *src, size_t n);
void	ft_bzero(void *dst, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
void	test_comp(float a, float b);
void	test_float_equal(void);
char	ft_float_equal(float a, float b);

/*
** src/vector
*/

void	matvect(const t_mat mat, t_vect vect, t_vect buf);
void	new_vect(t_vect new, const float x, const float y, const float z);
float	scalar_prod(const t_vect u, const t_vect v);
float	norm_vect(const t_vect vect);
void	cross_prod(t_vect lhs, t_vect rhs, t_vect buf);
void	print_vect(t_vect vect);
void	print_point(t_point point);
void	test_prod(void);
void	test_basic(void);
void	t3(t_vect *v);
void	t2(t_vect v);
void	test(void);
void	test3(void);
void	test_typedef(void);

/*
** src/matrix
*/

void	add(t_mat lhs, const t_mat rhs, t_mat buf);
void	dot_mat(t_mat lhs, t_mat rhs, t_mat buf);
void	print_mat(t_mat mat);
void	trans(const t_vect vect, t_mat mat);
void	rot(t_mat ret, const float alpha, const float beta, const float gamma);
void	test_add(void);
void	test_rot(void);

/*
** src/read
*/

void	read_error(void);
char	read_map(const char * const str);
void	print_camera(void);
void	print_plan(union u_o *p);
void	print_sphere(union u_o *s);
void	print_cylindre(union u_o *c);
void	print_cone(union u_o *c);
void	read_objects(const int fd);
int		read_number(const int fd, const char end, int *n, char *flag);
float	read_float(const int fd, const char end);
void	read_pos(const int fd, const void *addr);
void	read_plan(const int fd, union u_o * const u);
void	read_sphere(const int fd, union u_o * const u);
void	read_cylindre(const int fd, union u_o * const u);
void	read_cone(const int fd, union u_o * const u);

#endif
