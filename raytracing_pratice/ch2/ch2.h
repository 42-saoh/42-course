#ifndef CH2_H
# define CH2_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
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

void				show_gradation(int is_save);
t_img_data			*create_img_data(int width, int height);
void				draw_gradaitiong(t_img_data *data);
t_vec				*vec_create(double x, double y, double z);
int					get_color_val(t_vec *color);
t_img_data			*free_img_data(t_img_data *data);

#endif
