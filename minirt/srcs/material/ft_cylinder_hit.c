/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 16:00:05 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			*set_cylinder_normal(t_cylinder *cy, t_hit_record *rec)
{
	t_vec		*tmp;
	t_vec		*p_center;
	t_vec		*result;

	tmp = vec_sub(rec->p, cy->center);
	p_center = vec_mul_const(cy->normal, vec_dot(cy->normal, tmp));
	p_center = vec_add_apply(p_center, cy->center);
	result = vec_unit_apply(vec_sub(rec->p, p_center));
	free(tmp);
	free(p_center);
	return (result);
}

int				check_cap_hitrange(void *cy, t_ray *r, t_hit_record *rec)
{
	if (rec->p)
		reset_hit_record(rec);
	rec->p = ray_at(r, rec->t);
	rec->normal = vec_dup(((t_cylinder *)cy)->normal);
	hit_set_normal(rec, r);
	rec->color = vec_dup(((t_cylinder *)cy)->color);
	return (1);
}

int				check_cylinder_hitrange(void *cy, t_ray *r, t_hit_record *rec)
{
	if (rec->p)
		reset_hit_record(rec);
	rec->p = ray_at(r, rec->t);
	rec->normal = set_cylinder_normal((t_cylinder *)cy, rec);
	hit_set_normal(rec, r);
	rec->color = vec_dup(((t_cylinder *)cy)->color);
	return (1);
}

int				cylinder_hit(void *cy, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	double		cy_t;
	double		cap_t;

	cy_t = solve_cylinder_t((t_cylinder *)cy, r, info);
	cap_t = solve_cap_t((t_cylinder *)cy, r, info);
	if (cy_t == INFINITY && cap_t == INFINITY)
		return (0);
	if (cy_t < cap_t)
	{
		rec->t = cy_t;
		return (check_cylinder_hitrange(cy, r, rec));
	}
	else
	{
		rec->t = cap_t;
		return (check_cap_hitrange(cy, r, rec));
	}
}
