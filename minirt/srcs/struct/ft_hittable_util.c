/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hittable_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:53:36 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 16:12:50 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				hittable_shadow(t_hittable *result, int obj_type)
{
	if (obj_type == OBJ_SPHERE)
		result->s_hit = &sphere_s_hit;
	else if (obj_type == OBJ_PLANE)
		result->s_hit = &plane_s_hit;
	else if (obj_type == OBJ_CYLINDER)
		result->s_hit = &cylinder_s_hit;
	else if (obj_type == OBJ_TRIANGLE)
		result->s_hit = &triangle_s_hit;
	else if (obj_type == OBJ_SQUARE)
		result->s_hit = &square_s_hit;
	else if (obj_type == OBJ_LIGHT)
		result->s_hit = NULL;
	else if (obj_type == OBJ_AMBIENT)
		result->s_hit = NULL;
}

t_hittable			*hittable_create(void *obj, int obj_type)
{
	t_hittable		*result;

	result = (t_hittable *)malloc(sizeof(t_hittable));
	result->obj = obj;
	result->obj_type = obj_type;
	if (obj_type == OBJ_SPHERE)
		result->hit = &sphere_hit;
	else if (obj_type == OBJ_PLANE)
		result->hit = &plane_hit;
	else if (obj_type == OBJ_CYLINDER)
		result->hit = &cylinder_hit;
	else if (obj_type == OBJ_TRIANGLE)
		result->hit = &triangle_hit;
	else if (obj_type == OBJ_SQUARE)
		result->hit = &square_hit;
	else if (obj_type == OBJ_LIGHT)
		result->hit = NULL;
	else if (obj_type == OBJ_AMBIENT)
		result->hit = NULL;
	hittable_shadow(result, obj_type);
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
	if (h->obj_type == OBJ_LIGHT)
		free_light(h->obj);
	if (h->obj_type == OBJ_AMBIENT)
		free_ambient(h->obj);
	free(h);
}
