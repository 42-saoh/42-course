#include "ch6.h"

void				set_camera_llc(t_camera *cam, t_vec *lookat)
{
	t_vec			*tmp;

	vec_div_const_apply(cam->horizontal, 2.0);
	vec_div_const_apply(cam->vertical, 2.0);
	tmp = vec_add(cam->horizontal, cam->vertical);
	vec_add_apply(tmp, lookat);
	cam->lower_left_corner = vec_sub(cam->origin, tmp);
	vec_mul_const_apply(cam->horizontal, 2.0);
	vec_mul_const_apply(cam->vertical, 2.0);
	free(tmp);
}

t_camera			*camera_new(double aspect_ratio)
{
	t_camera		*result;
	t_vec			*tmp;

	result = (t_camera *)malloc(sizeof(t_camera));
	result->aspect_ratio = aspect_ratio;
	result->origin = vec_create(0, 0, 0);
	result->horizontal = vec_create(2.0 * aspect_ratio, 0, 0);
	result->vertical = vec_create(0, 2.0, 0);
	tmp = vec_create(0, 0, 1.0);
	set_camera_llc(result, tmp);
	free(tmp);
	return (result);
}

t_ray				*camera_get_ray(t_camera *cam, double u, double v)
{
	t_vec			*tmp;
	t_vec			*tmp2;
	t_vec			*tmp3;

	tmp2 = vec_mul_const(cam->horizontal, u);
	tmp3 = vec_mul_const(cam->vertical, v);
	tmp = vec_add(cam->lower_left_corner, tmp2);
	vec_add_apply(tmp, tmp3);
	vec_sub_apply(tmp, cam->origin);
	free(tmp2);
	free(tmp3);
	return (ray_create(cam->origin, tmp));
}

void				free_camera(t_camera *cam)
{
	free(cam->horizontal);
	free(cam->vertical);
	free(cam->lower_left_corner);
	free(cam->origin);
	free(cam);
}
