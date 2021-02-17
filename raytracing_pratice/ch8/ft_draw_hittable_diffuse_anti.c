#include "ch8.h"

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

t_vec				*get_recursive_color(t_list *lst, t_hitlst_info **info, int depth, int *is_free)
{
	t_vec			*target;
	t_vec			*tmp;
	t_ray			*ray;
	double			t;

	if (depth <= 0)
		return (vec_create(0, 0, 0));
	if (hitlst_hit(lst, *info))
	{
		target = vec_add_apply(vec_random_in_hemisphere((*info)->rec->normal), (*info)->rec->p);
		tmp = vec_dup((*info)->rec->p);
		ray = ray_create(tmp, vec_sub_apply(target, (*info)->rec->p));
		free_hitlst_info(*info, *is_free);
		*is_free = 1;
		*info = hitlst_info_new(ray);
		return (vec_mul_const_apply(get_recursive_color(lst, info, depth - 1, is_free), 0.5));
	}
	t = 0.5 * ((vec_unit_apply((*info)->ray->dir))->y + 1.0);
	target = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
	tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
	vec_add_apply(target, tmp);
	free(tmp);
	return (target);
}

void				get_hittable_diffuse_color(t_list *lst, t_hitlst_info **info, t_vec *color)
{
	t_vec			*target;
	int				is_free;

	is_free = 0;
	target = get_recursive_color(lst, info, REFLECT_DEPTH, &is_free);
	vec_add_apply(color, target);
	free(target);
	free_hitlst_info(*info, is_free);
}

void				draw_hittable_diffuse_anti(t_camera *cam, t_list *lst)
{
	int				x;
	int				y;
	int				locate;
	t_vec			*color;
	t_hitlst_info	*lst_info;

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
				lst_info = get_hitlst_by_locate(x, y, cam);
				get_hittable_diffuse_color(lst, &lst_info, color);
				locate++;
			}
			cam->data->img[x][y] = get_color_sample_gamma(color);
			free(color);
			x++;
		}
		y--;
	}
}
