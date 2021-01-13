#include "ch5.h"

t_sky_info			*init_sky_info(double v_w, double v_h, double f_l)
{
	t_sky_info		*result;

	result = (t_sky_info *)malloc(sizeof(t_sky_info));
	result->viewport_width = v_w;
	result->viewport_height = v_h;
	result->focal_length = f_l;
	return (result);
}
