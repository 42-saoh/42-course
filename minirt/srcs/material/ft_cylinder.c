/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:58:51 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder		*init_cylinder(t_vec *center, t_vec *normal,
		t_cyvar cy, t_vec *color)
{
	t_cylinder	*result;

	result = (t_cylinder *)malloc(sizeof(t_cylinder));
	result->center = center;
	result->normal = vec_unit_apply(normal);
	result->radius = (cy.diameter) / 2;
	result->height = cy.height;
	result->t_center = vec_add_apply(vec_mul_const(result->normal,
				result->height / 2), center);
	result->b_center = vec_add_apply(vec_mul_const(result->normal,
				-(result->height) / 2), center);
	result->color = color;
	return (result);
}

void			free_cylinder(t_cylinder *cy)
{
	free(cy->center);
	free(cy->t_center);
	free(cy->b_center);
	free(cy->color);
	free(cy->normal);
	free(cy);
}
