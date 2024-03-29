/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitlst_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:53:15 by saoh              #+#    #+#             */
/*   Updated: 2021/03/19 15:41:22 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hitlst_info			*hitlst_info_new(t_ray *r)
{
	t_hitlst_info		*result;

	result = (t_hitlst_info *)malloc(sizeof(t_hitlst_info));
	result->ray = r;
	result->t_min = HIT_T_MIN;
	result->t_max = INFINITY;
	result->rec = hit_record_new();
	return (result);
}

void					free_hitlst_info(t_hitlst_info *info,
		int is_ray_ori_free)
{
	ray_free(info->ray, is_ray_ori_free);
	free_hit_record(info->rec);
	free(info);
}

t_hitlst_info			*get_hitlst_by_locate(int w, int h, t_camera *cam)
{
	double				u;
	double				v;
	t_ray				*ray;

	u = ((double)w + random_double()) / (cam->data->width - 1);
	v = ((double)h + random_double()) / (cam->data->height - 1);
	ray = camera_get_ray(cam, u, v);
	return (hitlst_info_new(ray));
}
