#include "ch5.h"

int			hit_s_sphere(t_sphere *s, t_ray *r)
{
	t_vec		*oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, s->center);
	a = vec_dot(r->dir, r->dir);
	b = vec_dot(oc, r->dir) * 2.0;
	c = vec_dot(oc, oc) - s->radius * s->radius;
	discriminant = b * b - 4 * a * c;
	free(oc);
	return ((discriminant >= 0) ? 1 : 0);
}

void			draw_s_sphere(t_img_data *data, t_sky_info *info, t_sphere *s)
{
	t_vec		*color;
	t_sky		*my_sky;
	t_ray		*r;
	int			x;
	int			y;

	my_sky = init_sky(info, vec_create(0, 0, 0));
	my_sky->data = data;
	color = vec_create(1, 0, 0);
	y = data->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->width)
		{
			r = cal_sky_ray(x, y, my_sky);
			if (hit_s_sphere(s, r))
				data->img[x][y] = get_color_val(color);
			ray_free(r, 0);
			x++;
		}
		y--;
	}
	free(color);
	free_sky(my_sky, 1);
}
