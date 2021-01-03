#include "ch2.h"

double		clamp(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

int			get_color_val(t_vec *color)
{
	int		x;
	int		y;
	int		z;

	x = clamp(color->x, 0.0, 0.999) * 256.0;
	y = clamp(color->y, 0.0, 0.999) * 256.0;
	z = clamp(color->z, 0.0, 0.999) * 256.0;
	return (x << 16 | y << 8 | z);
}
