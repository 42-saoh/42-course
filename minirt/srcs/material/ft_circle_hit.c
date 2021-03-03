/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/03 18:18:30 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				is_incircle(t_hit_record *rec, void *p)
{
	t_vec		*tmp;

	tmp = vec_sub(rec->p, ((t_plane *)p)->center);
	if (sqrt(vec_dot(tmp, tmp)) <= ((t_plane *)p)->radius)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

double			is_infinite(double numerator, double denominator)
{
	if (denominator == 0)
		return (0);
	return (numerator / denominator);
}

int				circle_hit(void *p, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	t_vec		*oc;
	double		t;
	double		denominator;
	double		numerator;

	oc = vec_sub(((t_plane *)p)->center, r->orig);
	numerator = vec_dot(oc, ((t_plane *)p)->normal);
	denominator = vec_dot(r->dir, ((t_plane *)p)->normal);
	free(oc);
	t = is_infinite(numerator, denominator);
	if (info->t_min < t && t < info->t_max)
	{
		if (rec->p)
			reset_hit_record(rec);
		rec->t = t;
		rec->p = ray_at(r, t);
		if (!is_incircle(rec, p))
			return (0);
		rec->normal = vec_dup(((t_plane *)p)->normal);
		hit_set_normal(rec, r);
		rec->mat = info->mat;
		return (1);
	}
	return (0);
}
