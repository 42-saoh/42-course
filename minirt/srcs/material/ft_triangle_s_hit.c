/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle_s_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 17:33:44 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				is_s_in(t_vec *v1, t_vec *v0, t_vec *normal, t_vec *p)
{
	t_vec		*edge;
	t_vec		*vp;
	t_vec		*c;

	edge = vec_sub(v1, v0);
	vp = vec_sub(p, v0);
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

int				is_s_intriangle(t_triangle *tr, t_vec *p)
{
	if (!is_s_in(tr->v1, tr->v0, tr->normal, p))
		return (0);
	if (!is_s_in(tr->v2, tr->v1, tr->normal, p))
		return (0);
	if (!is_s_in(tr->v0, tr->v2, tr->normal, p))
		return (0);
	return (1);
}

int				triangle_s_hit(void *tr, t_ray *r, t_hitlst_info *info)
{
	t_vec		*oc;
	t_vec		*p;
	double		t;
	double		denominator;
	double		numerator;

	oc = vec_sub(((t_triangle *)tr)->v0, r->orig);
	numerator = vec_dot(oc, ((t_triangle *)tr)->normal);
	denominator = vec_dot(((t_triangle *)tr)->normal, r->dir);
	free(oc);
	if (denominator == 0)
		return (0);
	t = numerator / denominator;
	if (info->t_min < t && t < info->t_max)
	{
		p = ray_at(r, t);
		if (!is_s_intriangle((t_triangle *)tr, p))
		{
			free(p);
			return (0);
		}
		free(p);
		return (1);
	}
	return (0);
}
