/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:48:18 by saoh              #+#    #+#             */
/*   Updated: 2021/04/01 17:25:34 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H
# include "minirt.h"

typedef struct			s_img_data
{
	int					**img;
	int					width;
	int					height;
	double				aspect_ratio;
}						t_img_data;

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef struct			s_vars
{
	void				*mlx;
	void				*win;
	int					max_w;
	int					max_h;
}						t_vars;

typedef struct			s_mlx_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_mlx_data;

typedef struct			s_ray
{
	t_vec				*orig;
	t_vec				*dir;
}						t_ray;

typedef struct			s_sphere
{
	t_vec				*center;
	t_vec				*color;
	double				radius;
}						t_sphere;

typedef struct			s_plane
{
	t_vec				*center;
	t_vec				*normal;
	t_vec				*color;
}						t_plane;

typedef struct			s_cylinder
{
	t_vec				*center;
	t_vec				*t_center;
	t_vec				*b_center;
	t_vec				*normal;
	t_vec				*color;
	double				radius;
	double				height;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec				*v0;
	t_vec				*v1;
	t_vec				*v2;
	t_vec				*normal;
	t_vec				*color;
}						t_triangle;

typedef struct			s_square
{
	t_vec				*center;
	t_vec				*normal;
	t_vec				*color;
	t_vec				*v0;
	t_vec				*v1;
	t_vec				*v2;
	t_vec				*v3;
}						t_square;

typedef struct			s_hit_record
{
	t_vec				*p;
	t_vec				*normal;
	double				t;
	int					is_front_face;
	t_vec				*color;
}						t_hit_record;

typedef struct			s_camera
{
	t_img_data			*data;
	double				aspect_ratio;
	t_vec				*origin;
	t_vec				*lower_left_corner;
	t_vec				*horizontal;
	t_vec				*vertical;
}						t_camera;

typedef struct			s_hitlst_info
{
	t_ray				*ray;
	double				t_min;
	double				t_max;
	double				a;
	double				half_b;
	double				root_d;
	double				c;
	t_hit_record		*rec;
}						t_hitlst_info;

typedef struct			s_hittable
{
	void				*obj;
	int					obj_type;
	int					(*hit)(void *s, t_ray *r, t_hitlst_info *info,
			t_hit_record *rec);
	int					(*s_hit)(void *s, t_ray *r, t_hitlst_info *info);
}						t_hittable;

typedef struct			s_var
{
	int					a;
	int					b;
	double				choose_mat;
}						t_var;

typedef struct			s_cyvar
{
	double				height;
	double				diameter;
}						t_cyvar;

typedef struct			s_thread_info
{
	struct s_rt			*rt;
	t_camera			*cam;
	int					tnum;
}						t_thread_info;

typedef struct			s_pmt
{
	t_vec				*tmp;
	t_vec				*tmp2;
	t_vec				*p;
	double				plus_t;
	double				minus_t;
}						t_pmt;

typedef struct			s_light
{
	t_vec				*ori;
	t_vec				*color;
	double				intensity;
}						t_light;

typedef struct			s_light_info
{
	t_vec				*dir;
	t_vec				*intensity;
	double				length;
}						t_light_info;

typedef struct			s_ambient
{
	t_vec				*color;
	double				intensity;
}						t_ambient;

typedef struct			s_rt
{
	t_list				*lst;
	t_list				*l_lst;
	t_list				*c_lst;
	t_list				*t_lst;
	t_ambient			*am;
	t_img_data			*img;
	t_mlx_data			*mlx;
	t_vars				*vars;
	int					is_save;
	int					is_error;
}						t_rt;

typedef	struct			s_overlap
{
	int					r_ol;
	int					a_ol;
}						t_overlap;

typedef	struct			s_num
{
	double				val1;
	double				val2;
	double				val3;
	double				val4;
	double				val5;
	double				val6;
	double				val7;
	double				val8;
	double				val9;
	double				val10;
	double				val11;
	double				val12;
}						t_num;

#endif
