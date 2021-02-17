#include "ch9.h"

t_vec		*vec_mul_each_apply(t_vec *vec1, t_vec *vec2)
{
	vec1->x *= vec2->x;
	vec1->y *= vec2->y;
	vec1->z *= vec2->z;
	return (vec1);
}
