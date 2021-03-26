/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch10.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:58:00 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 18:41:44 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list			*put_hitlst_material(void)
{
	t_sphere	*s;
	t_triangle	*tr;
	t_cylinder	*cy;
	t_square	*sq;
	t_list		*hitlst;

	hitlst = hitlst_new();
	s = init_sphere(vec_create(0, -100.5, -1), 200, vec_create(100, 150, 50));
	hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
	tr = init_triangle(vec_create(4, -3, -5.0), vec_create(-4, -3, -5.0), vec_create(0, 3, -5.0), vec_create(100, 10, 200));
	hitlst_add(hitlst, (void *)tr, OBJ_TRIANGLE);
	cy = init_cylinder(vec_create(2, 0, -3.0), vec_create(0, 1, 0), 2, 2, vec_create(50, 150, 255));
	hitlst_add(hitlst, (void *)cy, OBJ_CYLINDER);
	sq = init_square(vec_create(-2, 0, -3.0), vec_create(0, 0, 1), 1, vec_create(150, 150, 255));
	hitlst_add(hitlst, (void *)sq, OBJ_SQUARE);
	return (hitlst);
}

t_list			*put_hitlst_plane(void)
{
	t_list		*hitlst;
	t_plane		*p;
	t_sphere	*s;
	t_cylinder	*cy;
	t_square	*sq;

	hitlst = hitlst_new();
	p = init_plane(vec_create(0, 0, -10), vec_create(0, 0, 1), vec_create(0, 255, 255));
	hitlst_add(hitlst, (void *)p, OBJ_PLANE);
	p = init_plane(vec_create(-5, 0, 0.0), vec_create(1, 0, 0), vec_create(255, 0, 0));
	hitlst_add(hitlst, (void *)p, OBJ_PLANE);
	p = init_plane(vec_create(5, 0, 0.0), vec_create(-1, 0, 0), vec_create(0, 0, 255));
	hitlst_add(hitlst, (void *)p, OBJ_PLANE);
	p = init_plane(vec_create(0, 5, 0.0), vec_create(0, -1, 0), vec_create(255, 0, 255));
	hitlst_add(hitlst, (void *)p, OBJ_PLANE);
	p = init_plane(vec_create(0, 0, 10), vec_create(0, 0, -1), vec_create(255, 255, 0));
	hitlst_add(hitlst, (void *)p, OBJ_PLANE);
	cy = init_cylinder(vec_create(2, 0, -3.0), vec_create(0, 1, 0), 2, 2, vec_create(50, 150, 255));
	hitlst_add(hitlst, (void *)cy, OBJ_CYLINDER);
	s = init_sphere(vec_create(0, 0, -3), 2, vec_create(100, 150, 150));
	hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
	sq = init_square(vec_create(-2, 0, -3.0), vec_create(0, 0, 1), 1, vec_create(150, 250, 150));
	hitlst_add(hitlst, (void *)sq, OBJ_SQUARE);
	return (hitlst);
}

t_list			*put_lightlst(void)
{
	t_list		*l_lst;
	t_light		*l;
	t_ambient	*am;

	l_lst = hitlst_new();
	am = init_ambient(0.5, vec_create(255, 255, 255));
	hitlst_add(l_lst, (void *)am, OBJ_AMBIENT);
	l = init_light(vec_create(2, 0, 2.0), 0.01, vec_create(255, 128, 128));
	hitlst_add(l_lst, (void *)l, OBJ_LIGHT);
	return (l_lst);
}

void			show_sphere_camera(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_camera	*cam;
	t_list		*hitlst;
	t_list		*l_lst;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	cam = camera_locate_new(vec_create(0.0, 2.0, -3.0), vec_create(0, 0, -1),
			aspect_ratio, get_radian(90));
	cam->data = img;
	hitlst = put_hitlst_plane();
	l_lst = put_lightlst();
	draw_hittable_pthread(cam, hitlst, l_lst);
	if (is_save)
		save_bmp(img, "ch10.rt");
	else
		mlx_show(img, "Sky");
	free_hitlst(hitlst);
	free_hitlst(l_lst);
	free_camera(cam);
	free_img_data(img);
}
