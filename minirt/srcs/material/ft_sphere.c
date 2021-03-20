/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/03/19 15:32:24 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere		*init_sphere(t_vec *center, double diameter, t_vec *color)
{
	t_sphere	*result;

	result = (t_sphere *)malloc(sizeof(t_sphere));
	result->center = center;
	result->radius = diameter / 2;
	result->color = color;
	return (result);
}

void			free_sphere(t_sphere *s)
{
	free(s->center);
	free(s->color);
	free(s);
}
