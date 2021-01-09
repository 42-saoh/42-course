#include "ch4.h"

void	show_sky(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_sky_info	*info;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	info = init_sky_info(2.0 * aspect_ratio, 2.0, 1.0);
	draw_sky(img, info);
	if (is_save)
		save_bmp(img, "ch2.rt");
	else
		mlx_show(img, "Gradation");
	free_img_data(img);
}
