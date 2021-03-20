/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_s_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 15:23:18 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				is_s_square(t_square *sq, t_vec *p)
{
	if (!is_s_in(sq->v1, sq->v0, sq->normal, p))
		return (0);
	if (!is_s_in(sq->v2, sq->v1, sq->normal, p))
		return (0);
	if (!is_s_in(sq->v3, sq->v2, sq->normal, p))
		return (0);
	if (!is_s_in(sq->v0, sq->v3, sq->normal, p))
		return (0);
	return (1);
}

int				square_s_hit(void *sq, t_ray *r, t_hitlst_info *info)
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
		if (!is_s_square((t_square *)sq, p))
		{
			free(p);
			return (0);
		}
		free(p);
		return (1);
	}
	return (0);
}
