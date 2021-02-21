/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_hittable_material.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:05 by saoh              #+#    #+#             */
/*   Updated: 2021/02/21 22:10:20 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_hitlst_info		*get_hitlst_by_locate(int w, int h, t_camera *cam)
{
	double			u;
	double			v;
	t_ray			*ray;

	u = ((double)w + random_double()) / (cam->data->width - 1);
	v = ((double)h + random_double()) / (cam->data->height - 1);
	ray = camera_get_ray(cam, u, v);
	return (hitlst_info_new(ray));
}

t_vec				*get_recur_mat_color(t_list *lst, t_hitlst_info **info,
		int depth, int *is_free)
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

void				*render(void *arg)
{
	int				w;
	int				h;
	int				locate;
	t_vec			*color;
	t_thread_info	*t_info;

	t_info = (t_thread_info *)arg;
	h = tinfo_get_y_init_value(t_info);
	while ((--h) >= (tinfo_get_step(t_info) * (t_info->tnum - 1)))
	{
		w = -1;
		while ((++w) < t_info->cam->data->width)
		{
			color = vec_create(0, 0, 0);
			locate = -1;
			while ((++locate) < ANTI_SAMPLES)
				get_hittable_material_color(t_info->lst,
						get_hitlst_by_locate(w, h, t_info->cam), color);
			t_info->cam->data->img[w][h] = get_color_sample_gamma(color);
			free(color);
		}
	}
	free(t_info);
	return (NULL);
}

void				draw_hittable_pthread(t_camera *cam, t_list *lst)
{
	pthread_t		*threads;
	int				pnum;
	t_thread_info	*info;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * PTHREAD_CNT);
	pnum = 1;
	while (pnum <= PTHREAD_CNT)
	{
		info = tinfo_new(cam, lst, pnum);
		pthread_create(&(threads[pnum - 1]), NULL, render, (void *)info);
		pnum++;
	}
	pnum = 1;
	while (pnum <= PTHREAD_CNT)
	{
		pthread_join(threads[pnum - 1], NULL);
		pnum++;
	}
	free(threads);
}
