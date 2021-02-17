#include "ch13.h"

t_vec	*vec_add_apply(t_vec *vec1, t_vec *vec2)
{
	vec1->x += vec2->x;
	vec1->y += vec2->y;
	vec1->z += vec2->z;
	return (vec1);
}

t_vec	*vec_sub_apply(t_vec *vec1, t_vec *vec2)
{
	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
	vec1->z -= vec2->z;
	return (vec1);
}

t_vec	*vec_div_const_apply(t_vec *vec, double val)
{
	vec->x /= val;
	vec->y /= val;
	vec->z /= val;
	return (vec);
}

t_vec	*vec_mul_const_apply(t_vec *vec, double val)
{
	vec->x *= val;
	vec->y *= val;
	vec->z *= val;
	return (vec);
}

t_vec	*vec_unit_apply(t_vec *vec)
{
	return (vec_div_const_apply(vec, vec_length(vec)));
}
