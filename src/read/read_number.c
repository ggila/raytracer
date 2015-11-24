/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:34:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 22:10:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	read_number(int fd, char end, int *n)
{
	int		r;
	int		res;
	char	b;

	res = 0;
	*n = 0;
	while ((r = read(fd, &b, 1)))
	{
		if ((r == -1) || (!ft_isdigit(b) && (b != end)))
			read_error();
		if (b == end)
			break;
		res += (b - '0');
		res *= 10;
		*n += 1;
	}
	return (res / 10);
}

float	read_float(int fd, char end)
{
	float	floor;
	float	virg;
	int		dec;

	floor = read_number(fd, '.', &dec);
	virg = read_number(fd, end, &dec);
	while (dec-- > 0)
		virg /= 10;
	return (floor + virg);
}

void	read_pos(int fd, void *addr)
{
	*(float*)addr = read_float(fd, ',');
	*((float*)addr + 1) = read_float(fd, ',');
	*((float*)addr + 2) = read_float(fd, '|');
}
