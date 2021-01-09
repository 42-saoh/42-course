#include "ch4.h"

double		vec_length_squared(t_vec *vec)
{
	return (pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
}

double		vec_length(t_vec *vec)
{
	return (sqrt(vec_length_squared(vec)));
}

t_vec		*vec_unit(t_vec *vec)
{
	return (vec_div_const(vec, vec_length(vec)));
}
