#include "minirt.h"

double		clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

double		get_radian(double degree)
{
	return (degree * MINI_PI / 180.0);
}
