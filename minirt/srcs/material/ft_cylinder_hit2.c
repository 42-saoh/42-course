/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_hit2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:39:32 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 16:02:39 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				is_incircle(t_ray *r, double t, t_vec *center, double radius)
{
	t_vec		*tmp;

	tmp = ray_at(r, t);
	tmp = vec_sub_apply(tmp, center);
	if (sqrt(vec_dot(tmp, tmp)) <= radius)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

double			solve_cap_t(t_cylinder *cy, t_ray *r, t_hitlst_info *info)
{
	t_vec		*oc;
	double		denominator;
	double		top_t;
	double		bot_t;

	denominator = vec_dot(r->dir, cy->normal);
	if (denominator == 0)
		return (INFINITY);
	oc = vec_sub(cy->t_center, r->orig);
	top_t = vec_dot(oc, cy->normal) / denominator;
	free(oc);
	if (!is_incircle(r, top_t, cy->t_center, cy->radius))
		top_t = INFINITY;
	oc = vec_sub(cy->b_center, r->orig);
	bot_t = vec_dot(oc, cy->normal) / denominator;
	free(oc);
	if (!is_incircle(r, bot_t, cy->b_center, cy->radius))
		bot_t = INFINITY;
	if (top_t <= info->t_min || top_t >= info->t_max)
		top_t = INFINITY;
	if (bot_t <= info->t_min || bot_t >= info->t_max)
		bot_t = INFINITY;
	if (top_t < bot_t)
		return (top_t);
	return (bot_t);
}

double			check_cylinder_t(t_cylinder *cy, t_ray *r, t_hitlst_info *info)
{
	t_pmt		ct;

	ct.plus_t = (-info->half_b + info->root_d) / info->a;
	ct.minus_t = (-info->half_b - info->root_d) / info->a;
	if (ct.minus_t > 0)
		ct.plus_t = ct.minus_t;
	if (info->t_min < ct.plus_t && ct.plus_t < info->t_max)
	{
		ct.p = ray_at(r, ct.plus_t);
		ct.tmp = vec_sub(ct.p, cy->t_center);
		ct.tmp2 = vec_sub(ct.p, cy->b_center);
		if (vec_dot(cy->normal, ct.tmp) > 0)
			ct.plus_t = INFINITY;
		if (vec_dot(cy->normal, ct.tmp2) < 0)
			ct.plus_t = INFINITY;
		free(ct.tmp);
		free(ct.tmp2);
		free(ct.p);
		return (ct.plus_t);
	}
	return (INFINITY);
}

double			solve_cylinder_t(t_cylinder *cy, t_ray *r, t_hitlst_info *info)
{
	t_vec		*oc;
	t_vec		*cr_rcy;
	t_vec		*cr_occy;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, cy->center);
	cr_rcy = vec_cross(r->dir, cy->normal);
	cr_occy = vec_cross(oc, cy->normal);
	info->a = vec_length_squared(cr_rcy);
	info->half_b = vec_dot(cr_rcy, cr_occy);
	c = vec_length_squared(cr_occy) - pow(cy->radius, 2.0);
	discriminant = pow(info->half_b, 2) - (info->a * c);
	free(cr_rcy);
	free(cr_occy);
	free(oc);
	if (discriminant < 0)
		return (INFINITY);
	info->root_d = sqrt(discriminant);
	return (check_cylinder_t(cy, r, info));
}
