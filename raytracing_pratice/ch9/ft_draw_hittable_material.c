#include "ch9.h"

t_vec				*get_sky_color_t(double t)
{
	t_vec			*target;
	t_vec			*tmp;

	tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
	target = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
	vec_add_apply(target, tmp);
	free(tmp);
	return (target);
}

t_hitlst_info		*get_hitlst_by_locate(int x, int y, t_camera *cam)
{
	double			u;
	double			v;
	t_ray			*ray;

	u = ((double)x + random_double()) / (cam->data->width -1);
	v = ((double)y + random_double()) / (cam->data->height -1);
	ray = camera_get_ray(cam, u, v);
	return (hitlst_info_new(ray));
}

t_vec				*get_recur_mat_color(t_list *lst, t_hitlst_info **info, int depth, int *is_free)
{
	t_material		*mat;
	t_material_info	mat_info;
	t_vec			*target;
	double			t;

	if (depth <= 0)
		return (vec_create(0, 0, 0));
	if (hitlst_hit(lst, *info))
	{
		mat = (*info)->rec->mat;
		if ((t = (*(mat->scatter))(mat, (*info)->ray, (*info)->rec, &mat_info)))
		{
			free_hitlst_info(*info, (*is_free)++);
			*info = hitlst_info_new(mat_info.scattered);
			target = vec_mul_each_apply(get_recur_mat_color(lst,
						info, depth - 1, is_free), mat_info.attenuation);
		}
		else
			target = vec_create(0, 0, 0);
		free_material_info(&mat_info, 0, !t);
		return (target);
	}
	t = 0.5 * ((vec_unit_apply((*info)->ray->dir))->y + 1.0);
	return (get_sky_color_t(t));
}

void				get_hittable_material_color(t_list *lst,
		t_hitlst_info *info, t_vec *color)
{
	t_vec			*target;
	int				is_free;

	is_free = 0;
	target = get_recur_mat_color(lst, &info, REFLECT_DEPTH, &is_free);
	vec_add_apply(color, target);
	free(target);
	free_hitlst_info(info, is_free);
}

void				draw_hittable_material(t_camera *cam, t_list *lst)
{
	int				x;
	int				y;
	int				locate;
	t_vec			*color;

	y = cam->data->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cam->data->width)
		{
			color = vec_create(0, 0, 0);
			locate = 0;
			while (locate < ANTI_SAMPLES)
			{
				get_hittable_material_color(lst,
						get_hitlst_by_locate(x, y, cam), color);
				locate++;
			}
			cam->data->img[x][y] = get_color_sample_gamma(color);
			free(color);
			x++;
		}
		y--;
	}
}
