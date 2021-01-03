#include "ch2.h"

void	show_gradation(int is_save)
{
	t_img_data	*img;

	img = create_img_data(256, 256);
	draw_gradaition(img);
	if (is_save)
		save_bmp(img, "ch2.rt");
	else
		mlx_show(img, "Gradation");
	free_img_data(img);
}
