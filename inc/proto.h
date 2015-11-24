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

char	read_map(char *str);

/*
** src/lib
*/

void	ft_bzero(void *dst, size_t n);

/*
** src/vector
*/

void	vect_cpy(t_vect *dst, t_vect *src);
void	new_vect(t_vect *new, float x, float y, float z);
void	dot_vect(t_mat *mat, t_vect *vect, t_vect *buf);
void	print_vect(t_vect *vect);

/*
** src/matrix
*/

void	add(t_mat *lhs, t_mat *rhs, t_mat *buf);
void	dot_mat(t_mat *lhs, t_mat *rhs, t_mat *buf);
void	print_mat(t_mat *mat);
void	trans(t_vect *vect, t_mat mat);
void	rot(t_mat *ret, float alpha, float beta, float gamma);

#endif
