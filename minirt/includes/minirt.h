/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:47:38 by saoh              #+#    #+#             */
/*   Updated: 2021/02/23 20:27:49 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "minirt_struct.h"
# include "minirt_const.h"
# include "minirt_vec.h"
# include "minirt_free.h"

void					show_sphere(int is_save);
void					show_sphere_camera(int is_save);
void					draw_hittable_pthread(t_camera *cam, t_list *lst);
t_img_data				*create_img_data(int width, int height);
int						get_color_val(t_vec *color);
t_vec					*get_color(int rgb);
void					save_bmp(t_img_data *data, char *filename);
void					mlx_show(t_img_data *data, char *title);
t_ray					*ray_create(t_vec *origin, t_vec *direction);
t_vec					*ray_at(t_ray *ray, double t);
t_sphere				*init_sphere(t_vec *center, double radius);
t_camera				*camera_new(double aspect_ratio);
t_ray					*camera_get_ray(t_camera *cam, double u, double v);
void					set_camera_llc(t_camera *cam, t_vec *lookat);
t_hit_record			*hit_record_new(void);
void					reset_hit_record(t_hit_record *rec);
void					hit_set_normal(t_hit_record *record, t_ray *r);
t_list					*hitlst_new(void);
void					hitlst_add(t_list *lst, void *obj, int obj_type);
int						hitlst_hit(t_list *lst, t_hitlst_info *info);
t_hitlst_info			*hitlst_info_new(t_ray *r);
t_hittable				*hittable_create(void *obj, int obj_type);
int						check_sphere_hitrange(void *s, t_ray *r,
		t_hitlst_info *info, t_hit_record *rec);
int						sphere_hit(void *s, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec);
int						cal_hittable_color(t_list *lst, t_hitlst_info *info);
double					random_double(void);
double					random_double_range(double min, double max);
int						get_color_sample_gamma(t_vec *color);
t_hitlst_info			*get_hitlst_by_locate(int w, int h, t_camera *cam);
t_material				*mat_lambertian_new(t_vec *color);
int						lambertian_scatter(t_material *mat, t_ray *ray_in,
		t_hit_record *rec, t_material_info *info);
t_material				*mat_metal_new(t_vec *color, double fuzz);
int						metal_scatter(t_material *mat, t_ray *ray_in,
		t_hit_record *rec, t_material_info *info);
t_material_info			*material_info_new(void);
t_material				*material_new(int mat_type, t_vec *color);
t_material				*material_dup(t_material *mat);
void					hitlst_mat_add(t_list *lst, void *obj, int obj_type,
		t_material *mat);
t_hittable				*hittable_mat_create(void *obj, int obj_type,
		t_material *mat);
t_camera				*camera_locate_new(t_vec *lookfrom, t_vec *lookat,
		double aspect_ratio, double vfov);
double					clamp(double val, double min, double max);
double					get_radian(double degree);
t_thread_info			*tinfo_new(t_camera *cam, t_list *lst, int tnum);
int						tinfo_get_step(t_thread_info *info);
int						tinfo_get_y_init_value(t_thread_info *info);

#endif
