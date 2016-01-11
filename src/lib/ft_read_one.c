#include "raytracer.h"

int			read_one(int fd, char *b)
{
	int r;

	r = read(fd, b, 1);
	if (r == -1)
		ft_errno(READ, -1, FATAL);
	return (r);
}
