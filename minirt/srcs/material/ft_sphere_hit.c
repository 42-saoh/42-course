/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/19 15:29:31 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_sphere_hitrange(void *s, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	t_pmt		st;

	st.plus_t = (-info->half_b + info->root_d) / info->a;
	st.minus_t = (-info->half_b - info->root_d) / info->a;
	if (st.minus_t > 0)
		st.plus_t = st.minus_t;
	if (info->t_min < st.plus_t && st.plus_t < info->t_max)
	{
		if (rec->p)
			reset_hit_record(rec);
		rec->t = st.plus_t;
		rec->p = ray_at(r, st.plus_t);
		rec->normal = vec_sub(rec->p, ((t_sphere *)s)->center);
		vec_div_const_apply(rec->normal, ((t_sphere *)s)->radius);
		hit_set_normal(rec, r);
		rec->color = vec_dup(((t_sphere *)s)->color);
		return (1);
	}
	return (0);
}

int				sphere_hit(void *s, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	t_vec		*oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, ((t_sphere *)s)->center);
	a = vec_dot(r->dir, r->dir);
	half_b = vec_dot(oc, r->dir);
	c = vec_dot(oc, oc) - pow(((t_sphere *)s)->radius, 2);
	discriminant = pow(half_b, 2) - (a * c);
	free(oc);
	if (discriminant < 0)
		return (0);
	info->a = a;
	info->half_b = half_b;
	info->root_d = sqrt(discriminant);
	return (check_sphere_hitrange(s, r, info, rec));
}
