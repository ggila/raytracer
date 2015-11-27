/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:34:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 07:23:27 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	read_number(const int fd, const char end, int *n, char *flag)
{
	int		r;
	int		res;
	char	b;

	res = 0;
	*n = 0;
	while ((r = read(fd, &b, 1)))
	{
		if (b == '-' && (*n == 0))
			*flag = 1;
		else
		{
			if ((r == -1) || (!ft_isdigit(b) && (b != end)))
				read_error();
			if (b == end)
				break;
			res += (b - '0');
			res *= 10;
			*n += 1;
		}
	}
	return (res / 10);
}

float	read_float(const int fd, const char end)
{
	float	floor;
	float	virg;
	int		dec;
	char	sign;

	sign = 0;
	floor = read_number(fd, '.', &dec, &sign);
	virg = read_number(fd, end, &dec, &sign);
	while (dec-- > 0)
		virg /= 10;
	return ((sign ? -1 : 1) * (floor + virg));
}

void	read_pos(const int fd, const void *addr)
{
	float	*f;

	f = (float*)addr;
	*f = read_float(fd, ',');
	*(f + 1) = read_float(fd, ',');
	*(f + 2) = read_float(fd, '|');
}
