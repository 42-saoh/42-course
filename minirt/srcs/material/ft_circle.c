/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/03/03 12:32:16 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane		*init_circle(t_vec *center, t_vec *normal, double radius)
{
	t_plane	*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	result->center = center;
	result->normal = normal;
	result->radius = radius;
	return (result);
}
