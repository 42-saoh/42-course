#include "minirt.h"

double		clamp(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

double		get_radian(double degree)
{
	return (degree * MINI_PI / 180.0);
}
