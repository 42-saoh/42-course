#include "ch5.h"

t_sky			*init_sky(t_sky_info *info, t_vec *origin)
{
	t_sky		*result;
	t_vec		*tmp;
	t_vec		*tmp2;
	t_vec		*tmp3;

	result = (t_sky *)malloc(sizeof(t_sky));
	result->origin = origin;
	result->horizontal = vec_create(info->viewport_width, 0, 0);
	result->vertical = vec_create(0, info->viewport_height, 0);
	vec_div_const_apply(result->horizontal, 2.0);
	vec_div_const_apply(result->vertical, 2.0);
	tmp = vec_add(result->horizontal, result->vertical);
	tmp2 = vec_create(0, 0, info->focal_length);
	tmp3 = vec_add(tmp, tmp2);
	result->lower_left_corner = vec_sub(origin, tmp3);
	vec_mul_const_apply(result->horizontal, 2.0);
	vec_mul_const_apply(result->vertical, 2.0);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (result);
}

int				cal_sky_color(t_ray *r)
{
	t_vec		*tmp;
	t_vec		*tmp2;
	t_vec		*tmp3;
	double		t;
	int			result;

	tmp = vec_unit(r->dir);
	t = 0.5 * (tmp->y + 1.0);
	tmp3 = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
	tmp2 = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
	vec_add_apply(tmp3, tmp2);
	result = get_color_val(tmp3);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (result);
}

void			free_sky(t_sky *my_sky, int is_origin_free)
{
	free(my_sky->horizontal);
	free(my_sky->vertical);
	free(my_sky->lower_left_corner);
	if (is_origin_free)
		free(my_sky->origin);
	free(my_sky);
}

void			draw_sky(t_img_data *data, t_sky_info *info)
{
	t_sky		*my_sky;
	t_ray		*r;
	int			x;
	int			y;

	my_sky = init_sky(info, vec_create(0, 0, 0));
	my_sky->data = data;
	y = data->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->width)
		{
			r = cal_sky_ray(x, y, my_sky);
			data->img[x][y] = cal_sky_color(r);
			ray_free(r, 0);
			x++;
		}
		y--;
	}
	free_sky(my_sky, 1);
}
