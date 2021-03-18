/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch10.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:58:00 by saoh              #+#    #+#             */
/*   Updated: 2021/03/18 14:13:17 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list			*put_hitlst_material(void)
{
	t_sphere	*s;
	t_list		*hitlst;
	t_material	*mat;

	hitlst = hitlst_new();
	s = init_sphere(vec_create(0, 0, -1), 0.5);
	mat = mat_lambertian_new(vec_create(0.7, 0.3, 0.3));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	s = init_sphere(vec_create(0, -100.5, -1), 100);
	mat = mat_lambertian_new(vec_create(0.8, 0.8, 0));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	s = init_sphere(vec_create(-1, 0, -1), 0.5);
	mat = mat_metal_new(vec_create(0.8, 0.8, 0.8), 0.3);
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	s = init_sphere(vec_create(1, 0, -1), 0.5);
	mat = mat_metal_new(vec_create(0.8, 0.6, 0.2), 0.7);
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	return (hitlst);
}

t_list			*put_hitlst_plane(void)
{
	t_cylinder	*cy;
	t_sphere	*s;
	t_triangle	*tr;
	t_square	*sq;
	t_plane		*p;
	t_list		*hitlst;
	t_material	*mat;

	hitlst = hitlst_new();
	cy = init_cylinder(vec_create(0, 0, -5), vec_create(0, 1, 0), 2, 2);
	mat = mat_lambertian_new(vec_create(0.7, 0.8, 0.7));
	hitlst_mat_add(hitlst, (void *)cy, OBJ_CYLINDER, mat);
	free_material(mat);
	s = init_sphere(vec_create(0, 0, -3), 1);
	mat = mat_lambertian_new(vec_create(0.8, 0.8, 0));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	sq = init_square(vec_create(0, 0, -1), vec_create(0, 1, 0), 1);
	mat = mat_lambertian_new(vec_create(0.5, 1.0, 0.7));
	hitlst_mat_add(hitlst, (void *)sq, OBJ_SQUARE, mat);
	free_material(mat);
	tr = init_triangle(vec_create(-1, 0, 1), vec_create(1, 0, 1), vec_create(0, 1, 1));
	mat = mat_lambertian_new(vec_create(0.5, 0.4, 0.2));
	hitlst_mat_add(hitlst, (void *)tr, OBJ_TRIANGLE, mat);
	free_material(mat);
	p = init_plane(vec_create(0, 0, -7), vec_create(0, 0, 1));
	mat = mat_lambertian_new(vec_create(1.0, 1.0, 0.7));
	hitlst_mat_add(hitlst, (void *)p, OBJ_PLANE, mat);
	free_material(mat);
	return (hitlst);
}

void			show_sphere_camera(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_camera	*cam;
	t_list		*hitlst;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	cam = camera_locate_new(vec_create(4, 3, 0), vec_create(0, 0, -1),
			aspect_ratio, get_radian(90));
	cam->data = img;
	hitlst = put_hitlst_plane();
	draw_hittable_pthread(cam, hitlst);
	if (is_save)
		save_bmp(img, "ch10.rt");
	else
		mlx_show(img, "Sky");
	free_hitlst(hitlst);
	free_camera(cam);
	free_img_data(img);
}
