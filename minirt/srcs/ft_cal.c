/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:03:43 by saoh              #+#    #+#             */
/*   Updated: 2021/02/23 20:31:45 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double				clamp(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

double				get_radian(double degree)
{
	return (degree * MINI_PI / 180.0);
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
