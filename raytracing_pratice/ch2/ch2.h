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

#endif
