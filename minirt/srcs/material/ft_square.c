/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/03/19 15:13:47 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square		*init_square(t_vec *center, t_vec *normal,
		double h_ss, t_vec *color)
{
	t_square	*result;
	t_vec		*vup;
	t_vec		*w;
	t_vec		*h;

	result = (t_square *)malloc(sizeof(t_square));
	result->center = center;
	result->normal = vec_unit_apply(normal);
	result->color = color;
	vup = vec_create(0, 1, 0);
	if (vec_is_parallel(vup, normal))
	{
		free(vup);
		vup = vec_create(1, 0, 0);
	}
	w = vec_cross_apply(vup, normal);
	h = vec_cross(w, normal);
	result->v0 = vec_add_apply(vec_add(vec_mul_const_apply(w, -h_ss),
				vec_mul_const_apply(h, h_ss)), center);
	result->v1 = vec_add_apply(vec_add(vec_mul_const_apply(w, -1), h), center);
	result->v2 = vec_add_apply(vec_add(vec_mul_const_apply(h, -1), w), center);
	result->v3 = vec_add_apply(vec_add(vec_mul_const_apply(w, -1), h), center);
	free(w);
	free(h);
	return (result);
}

void			free_square(t_square *sq)
{
	free(sq->center);
	free(sq->normal);
	free(sq->color);
	free(sq->v0);
	free(sq->v1);
	free(sq->v2);
	free(sq->v3);
	free(sq);
}
