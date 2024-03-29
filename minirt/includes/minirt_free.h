/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_free.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:48:06 by saoh              #+#    #+#             */
/*   Updated: 2021/03/25 17:16:06 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FREE_H
# define MINIRT_FREE_H
# include "minirt.h"

void					free_img_data(t_img_data *data);
void					ray_free(t_ray *ray, int is_orig_free);
void					free_sphere(t_sphere *s);
void					free_plane(t_plane *p);
void					free_triangle(t_triangle *tr);
void					free_square(t_square *sq);
void					free_cylinder(t_cylinder *cy);
void					free_camera(t_camera *cam);
void					free_hit_record(t_hit_record *rec);
void					free_hitlst(t_list *lst);
void					free_hitlst_info(t_hitlst_info *info,
		int is_ray_ori_free);
void					free_hittable(t_hittable *h);
void					free_light(t_light *l);
void					free_light_info(t_light_info *l_info);
void					free_ambient(t_ambient *am);
void					free_lsts(t_rt *rt);

#endif
