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


/*
** src/lib
*/

void	ft_bzero(void *dst, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int c);

/*
** src/vector
*/

void	vect_cpy(t_vect *dst, t_vect *src);
void	new_vect(t_vect *new, float x, float y, float z);
void	dot_vect(t_mat *mat, t_vect *vect, t_vect *buf);
void	print_vect(t_vect *vect);
void	print_point(t_point *point);

/*
** src/matrix
*/

void	add(t_mat *lhs, t_mat *rhs, t_mat *buf);
void	dot_mat(t_mat *lhs, t_mat *rhs, t_mat *buf);
void	print_mat(t_mat *mat);
void	trans(t_vect *vect, t_mat mat);
void	rot(t_mat *ret, float alpha, float beta, float gamma);

/*
** src/object
*/


/*
** src/read
*/

void	read_error(void);
char	read_map(char *str);
void	print_camera(void);
void	print_plan(union u_o *p);
void	print_sphere(union u_o *s);
void	print_cylindre(union u_o *c);
void	print_cone(union u_o *c);
void	check_token(int fd);
void	read_plan(int fd, union u_o *u);
void	read_sphere(int fd, union u_o *u);
void	read_cylindre(int fd, union u_o *u);
void	read_cone(int fd, union u_o *u);
int	read_number(int fd, char end, int *n, char *flag);
float	read_float(int fd, char end);
void	read_pos(int fd, void *addr);

#endif
