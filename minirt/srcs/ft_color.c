#include "minirt.h"

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

t_vec		*get_color(int rgb)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = (rgb & (0xFF << 16)) >> 16;
	result->y = (rgb & (0xFF << 8)) >> 8;
	result->z = rgb & 0xFF;
	return (result);
}

int			get_color_sample_gamma(t_vec *color)
{
	double	scale;
	double	x;
	double	y;
	double	z;

	scale = 1.0 / ANTI_SAMPLES;
	x = sqrt(color->x * scale);
	y = sqrt(color->y * scale);
	z = sqrt(color->z * scale);
	x = clamp(x, 0.0, 0.999) * 256.0;
	y = clamp(y, 0.0, 0.999) * 256.0;
	z = clamp(z, 0.0, 0.999) * 256.0;
	return ((int)x << 16 | (int)y << 8 | (int)z);
	
}
