#ifndef CH10_H
# define CH10_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

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

# define BMP_HEADER_SIZE 54
# define OBJ_SPHERE 1
# define HIT_T_MIN 0.001
# define ANTI_SAMPLES 50
# define REFLECT_DEPTH 5
# define MINI_PI 3.1415926535897932385
# define MAT_LAMBERTIAN 1
# define MAT_METAL 2

void					show_sphere_camera(int is_save);
t_img_data				*create_img_data(int width, int height);
t_vec					*vec_create(double x, double y, double z);
int						get_color_val(t_vec *color);
t_vec					*get_color(int rgb);
void					save_bmp(t_img_data *data, char *filename);
void					mlx_show(t_img_data *data, char *title);
void					free_img_data(t_img_data *data);
void					ray_free(t_ray *r, int is_orig_free);
t_vec					*vec_mul_const_apply(t_vec *vec, double val);
t_vec					*vec_div_const_apply(t_vec *vec, double val);
t_vec					*vec_add(t_vec *vec1, t_vec *vec2);
t_vec					*vec_sub(t_vec *vec1, t_vec *vec2);
t_vec					*vec_add_apply(t_vec *vec1, t_vec *vec2);
t_vec					*vec_sub_apply(t_vec *vec1, t_vec *vec2);
t_vec					*vec_unit_apply(t_vec *vec);
t_vec					*vec_mul_const(t_vec *vec1, double val);
t_vec					*vec_div_const(t_vec *vec1, double val);
double					vec_length_squared(t_vec *vec);
double					vec_length(t_vec *vec);
double					vec_dot(t_vec *vec1, t_vec *vec2);
t_vec					*vec_unit(t_vec *vec);
t_ray					*ray_create(t_vec *origin, t_vec *direction);
t_vec					*ray_at(t_ray *ray, double t);
void					ray_free(t_ray *ray, int is_orig_free);
t_sphere				*init_sphere(t_vec *center, double radius);
void					free_sphere(t_sphere *s);
t_camera				*camera_new(double aspect_ratio);
t_ray					*camera_get_ray(t_camera *cam, double u, double v);
void					set_camera_llc(t_camera *cam, t_vec *lookat);
void					free_camera(t_camera *cam);
t_hit_record			*hit_record_new(void);
void					reset_hit_record(t_hit_record *rec);
void					free_hit_record(t_hit_record *rec);
void					hit_set_normal(t_hit_record *record, t_ray *r);
t_list					*hitlst_new(void);
void					hitlst_add(t_list *lst, void *obj, int obj_type);
void					free_hitlst(t_list *lst);
int						hitlst_hit(t_list *lst, t_hitlst_info *info);
t_hitlst_info			*hitlst_info_new(t_ray *r);
void					free_hitlst_info(t_hitlst_info *info,
		int is_ray_ori_free);
t_hittable				*hittable_create(void *obj, int obj_type);
void					free_hittable(t_hittable *h);
void					free_material(t_material *mat);
int						check_sphere_hitrange(void *s, t_ray *r,
		t_hitlst_info *info, t_hit_record *rec);
int						sphere_hit(void *s, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec);
void					draw_hittable_material(t_camera *cam, t_list *lst);
int						cal_hittable_color(t_list *lst, t_hitlst_info *info);
double					random_double(void);
double					random_double_range(double min, double max);
t_vec					*vec_dup(t_vec *ori);
t_vec					*vec_random_unit(void);
t_vec					*vec_random_in_hemisphere(t_vec *normal);
int						get_color_sample_gamma(t_vec *color);
t_material				*mat_lambertian_new(t_vec *color);
int						lambertian_scatter(t_material *mat, t_ray *ray_in,
		t_hit_record *rec, t_material_info *info);
t_material				*mat_metal_new(t_vec *color, double fuzz);
int						metal_scatter(t_material *mat, t_ray *ray_in,
		t_hit_record *rec, t_material_info *info);
t_material_info			*material_info_new(void);
void					free_material_info(t_material_info *info,
		int is_ori_free, int is_scattered_free);
t_material				*material_new(int mat_type, t_vec *color);
t_material				*material_dup(t_material *mat);
void					hitlst_mat_add(t_list *lst, void *obj, int obj_type,
		t_material *mat);
t_hittable				*hittable_mat_create(void *obj, int obj_type,
		t_material  *mat);
t_vec					*vec_mul_each_apply(t_vec *vec1, t_vec *vec2);
t_vec					*vec_reflect(t_vec *v, t_vec *n);
t_vec					*vec_random_in_unit_sphere(void);
t_vec					*vec_random_range(double min, double max);
t_vec					*vec_cross(t_vec *vec1, t_vec *vec2);
t_vec					*vec_cross_apply(t_vec *vec1, t_vec *vec2);
int						vec_is_parallel(t_vec *vec1, t_vec *vec2);
t_camera				*camera_locate_new(t_vec *lookfrom, t_vec *lookat,
		double aspect_ratio, double vfov);
double					clamp(double x, double min, double max);
double					get_radian(double degree);

#endif
