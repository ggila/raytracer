/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 10:21:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	test_prod(void)
{
	t_vect	u, v, w;

	new_vect(u, 1,0.,0.);
	new_vect(v, 0.,1.,0.);
	cross_prod(u, v, w);
	print_vect(u);
	print_vect(v);
	print_vect(w);
	printf("\n");

	cross_prod(v, u, w);
	print_vect(u);
	print_vect(v);
	print_vect(w);
	printf("\n");

	new_vect(u, 1.,1.,0.);
	new_vect(v, 0.5,0.,0.5);
	cross_prod(u, v, w);
	print_vect(u);
	print_vect(v);
	print_vect(w);
	printf("\n");
}

void	test_basic(void)
{
	printf("test basic\n");
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
	print_mat(mat);
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

void	test(void)
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

void	test_typedef(void)
{
	test();
}

int	main(void)
{
//	test_basic();
	test_prod();
//	test_typedef();
	return (0);
}
