/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 18:00:17 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			is_infinite(double numerator, double denominator)
{
	if (denominator == 0)
		return (INFINITY);
	return (numerator / denominator);
}

int				is_square(t_square *sq, t_vec *p)
{
	if (!is_in(sq->v1, sq->v0, sq->normal, p))
		return (0);
	if (!is_in(sq->v2, sq->v1, sq->normal, p))
		return (0);
	if (!is_in(sq->v3, sq->v2, sq->normal, p))
		return (0);
	if (!is_in(sq->v0, sq->v3, sq->normal, p))
		return (0);
	return (1);
}

int				check_square_hitrange(void *sq, t_ray *r,
		t_hit_record *rec, double t)
{
	if (rec->p)
		reset_hit_record(rec);
	rec->t = t;
	rec->p = ray_at(r, t);
	rec->normal = vec_dup(((t_square *)sq)->normal);
	rec->color = vec_dup(((t_square *)sq)->color);
	hit_set_normal(rec, r);
	return (1);
}

int				square_hit(void *sq, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	t_vec		*oc;
	t_vec		*p;
	double		t;
	double		denominator;
	double		numerator;

	oc = vec_sub(((t_square *)sq)->center, r->orig);
	numerator = vec_dot(oc, ((t_square *)sq)->normal);
	denominator = vec_dot(r->dir, ((t_square *)sq)->normal);
	free(oc);
	t = is_infinite(numerator, denominator);
	if (info->t_min < t && t < info->t_max)
	{
		p = ray_at(r, t);
		if (is_square(sq, p))
		{
			free(p);
			return (check_square_hitrange(sq, r, rec, t));
		}
		free(p);
	}
	return (0);
}
