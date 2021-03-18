/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hittable_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:53:36 by saoh              #+#    #+#             */
/*   Updated: 2021/03/12 15:21:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable			*hittable_create(void *obj, int obj_type)
{
	t_hittable		*result;

	result = (t_hittable *)malloc(sizeof(t_hittable));
	result->obj = obj;
	result->obj_type = obj_type;
	result->mat = NULL;
	if (obj_type == OBJ_SPHERE)
		result->hit = &sphere_hit;
	if (obj_type == OBJ_PLANE)
		result->hit = &plane_hit;
	return (result);
}

void				free_hittable(t_hittable *h)
{
	if (h->obj_type == OBJ_SPHERE)
		free_sphere(h->obj);
	if (h->obj_type == OBJ_PLANE)
		free_plane(h->obj);
	if (h->obj_type == OBJ_TRIANGLE)
		free_triangle(h->obj);
	if (h->obj_type == OBJ_SQUARE)
		free_square(h->obj);
	if (h->obj_type == OBJ_CYLINDER)
		free_cylinder(h->obj);
	if (h->mat)
		free_material(h->mat);
	free(h);
}

t_hittable			*hittable_mat_create(void *obj, int obj_type,
		t_material *mat)
{
	t_hittable		*result;

	result = (t_hittable *)malloc(sizeof(t_hittable));
	result->obj = obj;
	result->obj_type = obj_type;
	result->mat = material_dup(mat);
	if (obj_type == OBJ_SPHERE)
		result->hit = &sphere_hit;
	if (obj_type == OBJ_PLANE)
		result->hit = &plane_hit;
	if (obj_type == OBJ_CYLINDER)
		result->hit = &cylinder_hit;
	if (obj_type == OBJ_TRIANGLE)
		result->hit = &triangle_hit;
	if (obj_type == OBJ_SQUARE)
		result->hit = &square_hit;
	return (result);
}
