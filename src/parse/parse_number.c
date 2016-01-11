// read_number.c
// ggilaber <ggilaber@student.42.fr>
// 2015/11/24 17:34:01 by ggilaber
// 2015/12/28 20:06:32 by ggilaber

#include "raytracer.h"

extern int g_line;

int	read_number(const int fd, const char end, int *n, char *flag)
{
	int		r;
	int		res;
	char	b;

	res = 0;
	*n = 0;
	while ((r = read_one(fd, &b)))
	{
		if (b == '-' && (*n == 0))
			*flag = 1;
		else
		{
			if ((!ft_isdigit(b) && (b != end)))
				ft_errno(WRONG_TRIPLE, g_line, FATAL);
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
