#include "ch13.h"

t_vec		*vec_add(t_vec *vec1, t_vec *vec2)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = vec1->x + vec2->x;
	result->y = vec1->y + vec2->y;
	result->z = vec1->z + vec2->z;
	return (result);
}

t_vec		*vec_sub(t_vec *vec1, t_vec *vec2)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = vec1->x - vec2->x;
	result->y = vec1->y - vec2->y;
	result->z = vec1->z - vec2->z;
	return (result);
}

t_vec		*vec_mul_const(t_vec *vec, double val)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = vec->x * val;
	result->y = vec->y * val;
	result->z = vec->z * val;
	return (result);
}

t_vec		*vec_div_const(t_vec *vec, double val)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = vec->x / val;
	result->y = vec->y / val;
	result->z = vec->z / val;
	return (result);
}

t_vec		*vec_reflect(t_vec *vec, t_vec *normal)
{
	t_vec	*result;
	t_vec	*tmp;

	tmp = vec_mul_const(normal, 2 * vec_dot(vec, normal));
	result = vec_sub(vec, tmp);
	free(tmp);
	return (result);
}
