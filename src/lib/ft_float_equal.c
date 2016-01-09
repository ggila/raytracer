#include "raytracer.h"

char	ft_float_equal(float a, float b)
{
	float diff;
	float largest;

	diff = fabs(a - b);
	a = fabs(a);
	b = fabs(b);
	largest = (b > a) ? b : a;
	if (diff <= largest * FLT_EPSILON)
		return (OK);
	return (KO);
}
