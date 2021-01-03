#include "ch2.h"

void			draw_gradaition(t_img_data *data)
{
	int			rgb;
	t_vec		*color;
	double		x;
	double		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			color = vec_create(x / data->width, y / data->height, 1.0 / 4.0);
			rgb = get_color_val(color);
			data->img[(int)x][(int)y] = rgb;
			free(color);
			x++;
		}
		y++;
	}
}
