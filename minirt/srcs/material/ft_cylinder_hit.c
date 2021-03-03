/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/02/28 19:28:40 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_cylinder_hitrange(void *c, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	int			plus_minus;
	double		t;

	plus_minus = 0;
	while (plus_minus < 2)
	{
		t = (-info->half_b + info->root_d *
				(plus_minus ? (1) : (-1))) / info->a;
		if (info->t_min < t && t < info->t_max)
		{
			if (rec->p)
				reset_hit_record(rec);
			rec->t = t;
			rec->p = ray_at(r, t);
			rec->normal = vec_sub(rec->p, ((t_cylinder *)c)->center);
			vec_div_const_apply(rec->normal, ((t_cylinder *)c)->radius);
			hit_set_normal(rec, r);
			rec->mat = info->mat;
			return (1);
		}
		plus_minus++;
	}
	return (0);
}

int				cylinder_hit(void *c, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	t_vec		*oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, ((t_cylinder *)c)->center);
	a = vec_dot(r->dir, r->dir) - pow(vec_dot(r->dir,
				((t_cylinder *)c)->unit_h), 2);
	half_b = vec_dot(oc, r->dir) - (vec_dot(r->dir, ((t_cylinder *)c)->unit_h)
		* vec_dot(oc, ((t_cylinder *)c)->unit_h));
	c = vec_dot(oc, oc) - pow(vec_dot(oc, ((t_cylinder *)c)->unit_h), 2)
		- pow(((t_cylinder *)c)->radius, 2);
	discriminant = pow(half_b, 2) - (a * c);
	free(oc);
	if (discriminant < 0)
		return (0);
	info->a = a;
	info->half_b = half_b;
	info->root_d = sqrt(discriminant);
	return (check_cylinder_hitrange(c, r, info, rec));
}
