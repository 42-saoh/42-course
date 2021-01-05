#ifndef CH2_H
# define CH2_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
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

# define BMP_HEADER_SIZE 54

void				show_gradation(int is_save);
t_img_data			*create_img_data(int width, int height);
void				draw_gradation(t_img_data *data);
t_vec				*vec_create(double x, double y, double z);
int					get_color_val(t_vec *color);
t_vec				*get_color(int rgb);
void				save_bmp(t_img_data *data, char *filename);
void				mlx_show(t_img_data *data, char *title);
void				free_img_data(t_img_data *data);

#endif
