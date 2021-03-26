/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_hittable_material.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:05 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 15:13:00 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double				cal_color(int vis, double c1, double c2, double c3)
{
	return (vis * c1 * 0.18 / M_PI * c2 * 5000 * c3);
}

t_vec				*get_light_color(t_light *l, t_hit_record *rec,
		t_list *lst, t_hitlst_info *info)
{
	t_vec			*color;
	t_light_info	*l_info;
	t_ray			*shadow_ray;
	double			tmpcolor;
	int				vis;

	l_info = init_light_info(l, info->rec->p);
	info->t_max = l_info->length;
	shadow_ray = ray_create(vec_add_apply(vec_mul_const(rec->normal, 0.0001),
				rec->p), vec_mul_const(l_info->dir, -1));
	vis = hitlst_sh_hit(lst, shadow_ray, info);
	tmpcolor = vec_dot(rec->normal, shadow_ray->dir);
	if (tmpcolor < 0)
		tmpcolor = 0;
	color = vec_create(cal_color(vis, rec->color->x, l_info->intensity->x,
				tmpcolor), cal_color(vis, rec->color->y, l_info->intensity->y,
					tmpcolor), cal_color(vis, rec->color->z,
						l_info->intensity->z, tmpcolor));
	free_light_info(l_info);
	ray_free(shadow_ray, 1);
	return (color);
}

void				get_hittable_material_color(t_rt *rt, t_list *l_lst,
		t_hitlst_info *info, t_vec *color)
{
	t_vec			*target;
	t_vec			*t_color;
	t_hittable		*hittable;

	if (hitlst_hit(rt->lst, info))
	{
		target = vec_mul_const_apply(vec_mul_each_apply(
					vec_dup(info->rec->color), rt->am->color),
				0.001 * rt->am->intensity);
		while (l_lst)
		{
			hittable = (t_hittable *)(l_lst->content);
			t_color = get_light_color(hittable->obj, info->rec, rt->lst, info);
			l_lst = l_lst->next;
			target = vec_add_apply(target, t_color);
		}
	}
	else
		target = vec_create(0, 0, 0);
	vec_add_apply(color, target);
	free(target);
	free_hitlst_info(info, 0);
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
		while ((++w) < t_info->rt->cam->data->width)
		{
			color = vec_create(0, 0, 0);
			locate = -1;
			while ((++locate) < ANTI_SAMPLES)
				get_hittable_material_color(t_info->rt, t_info->rt->l_lst,
						get_hitlst_by_locate(w, h, t_info->rt->cam), color);
			t_info->rt->cam->data->img[w][h] = get_color_sample_gamma(color);
			free(color);
		}
	}
	free(t_info);
	return (NULL);
}

void				draw_hittable_pthread(t_rt *rt)
{
	pthread_t		*threads;
	int				pnum;
	t_thread_info	*info;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * PTHREAD_CNT);
	pnum = 1;
	while (pnum <= PTHREAD_CNT)
	{
		info = tinfo_new(rt, pnum);
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
