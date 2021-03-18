/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_hit2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:39:32 by saoh              #+#    #+#             */
/*   Updated: 2021/03/18 13:29:19 by saoh             ###   ########.fr       */
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

int				check_cap_hitrange(void *cy, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	if (rec->p)
		reset_hit_record(rec);
	rec->p = ray_at(r, rec->t);
	rec->normal = vec_dup(((t_cylinder *)cy)->normal);
	hit_set_normal(rec, r);
	rec->mat = info->mat;
	return (1);
}

int				check_cylinder_hitrange(void *cy, t_ray *r,
		t_hitlst_info *info, t_hit_record *rec)
{
	if (rec->p)
		reset_hit_record(rec);
	rec->p = ray_at(r, rec->t);
	rec->normal = set_cylinder_normal((t_cylinder *)cy, rec);
	hit_set_normal(rec, r);
	rec->mat = info->mat;
	return (1);
}

