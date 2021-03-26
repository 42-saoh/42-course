/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:47:38 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 15:13:40 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define _USE_MATH_DEFINES
# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "minirt_struct.h"
# include "minirt_const.h"
# include "minirt_vec.h"
# include "minirt_free.h"
# include <stdio.h>

void					show_sphere(int is_save);
void					show_sphere_camera(int is_save);
void					draw_hittable_pthread(t_rt *rt);
t_img_data				*create_img_data(int width, int height);
t_img_data				*dup_img_data(t_img_data *img);
int						get_color_val(t_vec *color);
t_vec					*get_color(int rgb);
void					save_bmp(t_img_data *data, char *filename);
void					mlx_show(t_img_data *data, char *title);
t_ray					*ray_create(t_vec *origin, t_vec *direction);
t_vec					*ray_at(t_ray *ray, double t);
t_sphere				*init_sphere(t_vec *center, double radius, t_vec *color);
t_plane					*init_plane(t_vec *center, t_vec *normal, t_vec *color);
t_cylinder				*init_cylinder(t_vec *center, t_vec *normal,
		double radius, double height, t_vec *color);
t_triangle				*init_triangle(t_vec *v0, t_vec *v1, t_vec *v2, t_vec *color);
t_square				*init_square(t_vec *center, t_vec *normal, double h_ss, t_vec *color);
t_light					*init_light(t_vec *ori, double intensity, t_vec *color);
t_light_info			*init_light_info(t_light *light, t_vec *p);
t_ambient				*init_ambient(double intensity, t_vec *color);
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
int						plane_hit(void *p, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec);
int						cylinder_hit(void *cy, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec);
int						triangle_hit(void *tr, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec);
int						square_hit(void *sq, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec);
int						cal_hittable_color(t_list *lst, t_hitlst_info *info);
double					random_double(void);
double					random_double_range(double min, double max);
int						get_color_sample_gamma(t_vec *color);
t_hitlst_info			*get_hitlst_by_locate(int w, int h, t_camera *cam);
t_camera				*camera_locate_new(t_vec *lookfrom, t_vec *lookat,
		double aspect_ratio, double vfov);
double					clamp(double val, double min, double max);
double					get_radian(double degree);
t_thread_info			*tinfo_new(t_rt *rt, int tnum);
int						tinfo_get_step(t_thread_info *info);
int						tinfo_get_y_init_value(t_thread_info *info);
int						is_in(t_vec *v1, t_vec *v0, t_vec *normal, t_vec *p);
int						is_s_in(t_vec *v1, t_vec *v0, t_vec *normal, t_vec *p);
double					is_infinite(double numerator, double denominator);
double					solve_cylinder_t(t_cylinder *cy, t_ray *r,
		t_hitlst_info *info);
double					solve_cap_t(t_cylinder *cy, t_ray *r,
		t_hitlst_info *info);
int						hitlst_sh_hit(t_list *lst, t_ray *s_ray, t_hitlst_info *info);
int						sphere_s_hit(void *s, t_ray *r, t_hitlst_info *info);
int						plane_s_hit(void *p, t_ray *r, t_hitlst_info *info);
int						cylinder_s_hit(void *cy, t_ray *r, t_hitlst_info *info);
int						triangle_s_hit(void *tr, t_ray *r, t_hitlst_info *info);
int						square_s_hit(void *sq, t_ray *r, t_hitlst_info *info);
int						error_input(void);
int						error_file(void);
int						check_issave(char *s, t_rt *rt);
int						check_rt(char *f_name, t_rt *rt);
int						check_rt_lst(t_rt *rt);
int						parsing_rt(int fd, t_rt *rt);
char					*get_num(char *line, int *num);
char					*get_double(char *line, double *num);
char					*is_comma(char *line);
char					*cut_space(char *line);
void					set_image(char *line, t_rt *rt, t_overlap *ol);
void					set_ambient(char *line, t_rt *rt, t_overlap *ol);
void					set_camera(char *line, t_rt *rt);
void					set_light(char *line, t_rt *rt);
void					set_plane(char *line, t_rt *rt);
void					set_sphere(char *line, t_rt *rt);
void					set_square(char *line, t_rt *rt);
void					set_cylinder(char *line, t_rt *rt);
void					set_triangle(char *line, t_rt *rt);

#endif
