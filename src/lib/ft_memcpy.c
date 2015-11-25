/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:55:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/25 18:56:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return;
	i = 0;
	while (i < n / 8)
	{
		*((long unsigned int*)dst + i) = *((long unsigned int*)src + i);
		i += 8;
	}
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		++i;
	}
	return;
}
