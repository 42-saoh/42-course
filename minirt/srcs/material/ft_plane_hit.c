/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 17:25:12 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				plane_hit(void *p, t_ray *r, t_hitlst_info *info,
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
	if (denominator == 0)
		return (0);
	t = numerator / denominator;
	if (info->t_min < t && t < info->t_max)
	{
		if (rec->p)
			reset_hit_record(rec);
		rec->t = t;
		rec->p = ray_at(r, t);
		rec->normal = vec_dup(((t_plane *)p)->normal);
		hit_set_normal(rec, r);
		rec->color = vec_dup(((t_plane *)p)->color);
		return (1);
	}
	return (0);
}
