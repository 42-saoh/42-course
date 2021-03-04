/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/04 19:30:10 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				is_in(t_vec *v1, t_vec *v0, t_vec *normal,
		t_hit_record *rec)
{
	t_vec		*edge;
	t_vec		*vp;
	t_vec		*c;

	edge = vec_sub(v1, v0);
	vp = vec_sub(rec->p, v0);
	c = vec_cross(edge, vp);
	free(edge);
	free(vp);
	if (vec_dot(normal, c) < 0)
	{
		free(c);
		return (0);
	}
	free(c);
	return (1);
}

int				is_intriangle(t_triangle *tr, t_hit_record *rec)
{
	if (!is_in(tr->v1, tr->v0, tr->normal, rec))
		return (0);
	if (!is_in(tr->v2, tr->v1, tr->normal, rec))
		return (0);
	if (!is_in(tr->v0, tr->v2, tr->normal, rec))
		return (0);
	return (1);
}

int				triangle_hit(void *tr, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	double		t;
	double		denominator;
	double		numerator;
	double		d;

	d = vec_dot(((t_triangle *)tr)->normal, ((t_triangle *)tr)->v0);
	numerator = vec_dot(((t_triangle *)tr)->normal, r->orig) + d;
	denominator = vec_dot(((t_triangle *)tr)->normal, r->dir);
	if (denominator == 0)
		return (0);
	t = numerator / denominator;
	if (info->t_min < t && t < info->t_max)
	{
		if (rec->p)
			reset_hit_record(rec);
		rec->t = t;
		rec->p = ray_at(r, t);
		rec->normal = vec_dup(((t_triangle *)tr)->normal);
		if (!is_intriangle((t_triangle *)tr, rec))
			return (0);
		hit_set_normal(rec, r);
		rec->mat = info->mat;
		return (1);
	}
	return (0);
}
