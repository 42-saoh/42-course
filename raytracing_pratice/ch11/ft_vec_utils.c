#include "ch10.h"

double		vec_length_squared(t_vec *vec)
{
	return (pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
}

double		vec_length(t_vec *vec)
{
	return (sqrt(vec_length_squared(vec)));
}

double		vec_dot(t_vec *vec1, t_vec *vec2)
{
	return (vec1->x * vec2->x + vec1->y *vec2->y + vec1->z * vec2->z);
}

t_vec		*vec_cross(t_vec *vec1, t_vec *vec2)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = vec1->y * vec2->z - vec1->z * vec2->y;
	result->y = vec1->z * vec2->x - vec1->x * vec2->z;
	result->z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (result);
}

t_vec		*vec_unit(t_vec *vec)
{
	return (vec_div_const(vec, vec_length(vec)));
}
