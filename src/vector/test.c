/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/26 21:27:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	test1(void)
{
	printf("test1\n");
	t_mat mat;
	t_vect v1;
	t_vect v2;
	t_vect v3;
	int i;

	i = -1;
	ft_bzero(mat, MAT_SIZE);
	while (++i < 4)
	{
		int j = -1;
		while (++j < 4)
			mat[i][j] = i + j;
	}
	new_vect(v1, 2, 2, 0);
	print_mat(&mat);
	new_vect(v2, 1, 2, 3);
	print_vect(v2);
	matvect(mat, v2, v3);
	print_vect(v3);
	matvect(mat, v2, NULL);
	print_vect(v2);
}

void	t3(t_vect *v)
{
	printf("%p\n", *v);         //0x7fff59f0b950
	printf("%p\n", v);          //0x7fff59f0b950
	printf("%p\n", &v);         //0x7fff59f0b928
}

void	t2(t_vect v)
{
//	printf("%lu\t%lu\n", sizeof(v), sizeof(&v));
	printf("%p\n", v);          //0x7fff59f0b950
	printf("%p\n", &v);         //0x7fff59f0b928
}

void	test2(void)
{
	t_vect	v;

	printf("test2\n");
	printf("%lu\t%lu\n", sizeof(v), sizeof(&v));
	printf("%p\n", v);          //0x7fff59f0b950
	printf("%p\n", &v);         //0x7fff59f0b950
//	printf("%p\n", &(&v));      //error: cannot take the address of an rvalue of type 't_vect *' (aka 'float (*)[4]')
	t2(v);
}

void	test3(void)
{
	printf("hello world\n");
	printf("%c\n", "hello world"[6]);
}

int	main(void)
{
	test1();
//	test2();
//	test3();
	return (0);
}
