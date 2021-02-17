#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H
# include "minirt.h"

typedef struct			s_img_data
{
	int					**img;
	int					width;
	int					height;
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
	double				radius;
}						t_sphere;

typedef struct			s_hit_record
{
	t_vec				*p;
	t_vec				*normal;
	double				t;
	int					is_front_face;
	struct s_material	*mat;
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
	t_hit_record		*rec;
	struct s_material	*mat;
}						t_hitlst_info;

typedef struct			s_hittable
{
	void				*obj;
	int					obj_type;
	int					(*hit)(void *s, t_ray *r, t_hitlst_info *info,
			t_hit_record *rec);
	struct s_material	*mat;
}						t_hittable;

typedef struct			s_material_info
{
	t_vec				*attenuation;
	t_ray				*scattered;
}						t_material_info;

typedef struct			s_material
{
	int					(*scatter)(struct s_material *mat, t_ray *ray_in,
			t_hit_record *rec, t_material_info *info);
	int					mat_type;
	t_vec				*color;
	double				fuzz;
}						t_material;

typedef struct			s_var
{
	int					a;
	int					b;
	double				choose_mat;
}						t_var;

typedef struct			s_thread_info
{
	t_camera			*cam;
	t_list				*lst;
	int					tnum;
}						t_thread_info;

#endif
