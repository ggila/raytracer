/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:39:49 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 09:59:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	test_comp(float a, float b)
{
	printf("a: %.10f\nb: %.10f\nres: ", a, b);
	printf("%s", ft_float_equal(a, b) == OK ? "\033[32m==" : "\033[31m!=");
	printf("\033[00m\n\n");
}

void	test_float_equal(void)
{
	test_comp(1.,2.);
	test_comp(1.,1.);
	test_comp(1.,1.000001);
	test_comp(1.,1.0000004);
	test_comp(1.,1.0000001);

	t_vect u, v;
	new_vect(u, 1.,0.,0.);
	new_vect(v, 0.,1.,0.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(v, 1.,0.,0.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(v, 1.,1.,0.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(v, 0.,1.,1.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(u, 1.,1.,0.);
	new_vect(v, -1.,1.,0.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(u, 0.99,1.,0.);
	new_vect(v, -1.,1.,0.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(u, 0.9999999,1.,0.);
	new_vect(v, -1.,1.,0.);
	test_comp(scalar_prod(u,v), 0.);
	new_vect(u, 0.9999999999,1.,0.);
	new_vect(v, -1.,1.,0.);
	test_comp(scalar_prod(u,v), 0.);
}

int	main(void)
{
	test_float_equal();
	return (0);
}
