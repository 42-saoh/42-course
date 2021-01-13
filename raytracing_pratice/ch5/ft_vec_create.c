#include "ch5.h"

t_vec			*vec_create(double x, double y, double z)
{
	t_vec		*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}
