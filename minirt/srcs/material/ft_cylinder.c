/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/02/28 19:06:51 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder		*init_cylinder(t_vec *center, t_vec *normal, double radius,
		double height)
{
	t_cylinder	*result;
	t_vec		*h_center;

	result = (t_cylinder *)malloc(sizeof(t_cylinder));
	result->center = center;
	result->normal = normal;
	result->radius = radius;
	h_center = vec_add_apply(vec_mul_const(normal, height), result->center);
	result->unit_h = vec_unit_apply(vec_sub_apply(h_center, center));
	return (result);
}

void			free_cylinder(t_cylinder *c)
{
	free(c->center);
	free(c->unit_h);
	free(c->normal);
	free(c);
}
