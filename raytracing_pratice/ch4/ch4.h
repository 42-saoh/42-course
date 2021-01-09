#ifndef CH4_H
# define CH4_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

typedef struct		s_img_data
{
	int				**img;
	int				width;
	int				height;
}					t_img_data;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_mlx_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx_data;

typedef struct		s_sky_info
{
	double			viewport_width;
	double			viewport_height;
	double			focal_length;
}					t_sky_info;

typedef struct		s_sky
{
	t_img_data		*data;
	t_vec			*horizontal;
	t_vec			*vertical;
	t_vec			*lower_left_corner;
	t_vec			*origin;
}					t_sky;

typedef struct		s_ray
{
	t_vec			*orig;
	t_vec			*dir;
}					t_ray;

# define BMP_HEADER_SIZE 54

void				show_sky(int is_save);
t_img_data			*create_img_data(int width, int height);
void				draw_sky(t_img_data *data, t_sky_info *info);
t_vec				*vec_create(double x, double y, double z);
int					get_color_val(t_vec *color);
t_vec				*get_color(int rgb);
void				save_bmp(t_img_data *data, char *filename);
void				mlx_show(t_img_data *data, char *title);
void				free_img_data(t_img_data *data);
t_sky_info			*init_sky_info(double viewport_width,
		double viewport_height, double focal_length);
t_ray				*cal_sky_ray(int x, int y, t_sky *my_sky);
t_vec				*vec_mul_const_apply(t_vec *vec, double val);
t_vec				*vec_div_const_apply(t_vec *vec, double val);
t_vec				*vec_add(t_vec *vec1, t_vec *vec2);
t_vec				*vec_sub(t_vec *vec1, t_vec *vec2);
t_vec				*vec_add_apply(t_vec *vec1, t_vec *vec2);
t_vec				*vec_sub_apply(t_vec *vec1, t_vec *vec2);
t_vec				*vec_mul_const(t_vec *vec1, double val);
t_vec				*vec_div_const(t_vec *vec1, double val);
t_vec				*vec_unit(t_vec *vec);
t_ray				*ray_create(t_vec *origin, t_vec *direction);
void				ray_free(t_ray *ray, int is_orig_free);

#endif
