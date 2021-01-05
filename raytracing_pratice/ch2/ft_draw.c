#include "ch2.h"

void			draw_gradation(t_img_data *data)
{
	int			rgb;
	t_vec		*color;
	double		w;
	double		h;

	h = 0;
	while (h < data->height)
	{
		w = 0;
		while (w < data->width)
		{
			color = vec_create(w / data->width, h / data->height, 1.0 / 4.0);
			rgb = get_color_val(color);
			data->img[(int)w][(int)h] = rgb;
			free(color);
			w++;
		}
		h++;
	}
}
