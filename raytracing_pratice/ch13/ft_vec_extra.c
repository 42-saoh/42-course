#include "ch13.h"

t_vec		*vec_mul_each_apply(t_vec *vec1, t_vec *vec2)
{
	vec1->x *= vec2->x;
	vec1->y *= vec2->y;
	vec1->z *= vec2->z;
	return (vec1);
}

int			vec_is_parallel(t_vec *vec1, t_vec *vec2)
{
	double	dot;
	double	length;

	dot = vec_dot(vec1, vec2);
	dot = ((dot < 0) ? (-1 * dot) : dot);
	length = vec_length(vec1) * vec_length(vec2);
	return ((dot == length) ? 1 : 0);
}

t_vec		*vec_cross_apply(t_vec *vec1, t_vec *vec2)
{
	t_vec	*result;

	result = vec_cross(vec1, vec2);
	vec1->x = result->x;
	vec1->y = result->y;
	vec1->z = result->z;
	free(result);
	return (vec1);
}

