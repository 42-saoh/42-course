#include "ch4.h"

t_ray		*ray_create(t_vec *origin, t_vec *direction)
{
	t_ray	*result;

	result = (t_ray *)malloc(sizeof(t_ray));
	result->orig = origin;
	result->dir = direction;
	return (result);
}

void		ray_free(t_ray *ray, int is_orig_free)
{
	if (ray == NULL)
		return ;
	else if (is_orig_free && ray->orig != NULL)
		free(ray->orig);
	free(ray->dir);
	free(ray);
}
