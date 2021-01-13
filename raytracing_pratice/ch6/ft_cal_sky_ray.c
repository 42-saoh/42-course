#include "ch5.h"

t_ray		*cal_sky_ray(int x, int y, t_sky *my_sky)
{
	t_ray	*r;
	t_vec	*tmp;
	t_vec	*tmp2;

	tmp = vec_mul_const(my_sky->horizontal,
			(double)x / (my_sky->data->width -1));
	tmp2 = vec_mul_const(my_sky->vertical,
			(double)y / (my_sky->data->height -1));
	vec_add_apply(tmp, tmp2);
	vec_add_apply(tmp, my_sky->lower_left_corner);
	r = ray_create(my_sky->origin, vec_sub_apply(tmp, my_sky->origin));
	return (r);
}
