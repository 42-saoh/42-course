#include "ch9.h"

void	show_sphere_material(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_camera	*cam;
	t_sphere	*s;
	t_list		*hitlst;
	t_material	*mat;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	cam = camera_new(aspect_ratio);
	cam->data = img;
	hitlst = hitlst_new();
	s = init_sphere(vec_create(0, 0, -1), 0.5);
	mat = mat_lambertian_new(vec_create(0.7, 0.3, 0.3));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE,mat);
	free_material(mat);
	s = init_sphere(vec_create(0, -100.5, -1), 100);
	mat = mat_lambertian_new(vec_create(0.8, 0.8, 0));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE,mat);
	free_material(mat);
	s = init_sphere(vec_create(-1, 0, -1), 0.5);
	mat = mat_metal_new(vec_create(0.8, 0.8, 0.8), 0.3);
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE,mat);
	free_material(mat);
	s = init_sphere(vec_create(1, 0, -1), 0.5);
	mat = mat_metal_new(vec_create(0.8, 0.6, 0.2), 0.7);
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE,mat);
	free_material(mat);
	draw_hittable_material(cam, hitlst);
	if (is_save)
		save_bmp(img, "ch9.rt");
	else
		mlx_show(img, "Sky");
	free_hitlst(hitlst);
	free_camera(cam);
	free_img_data(img);
}
