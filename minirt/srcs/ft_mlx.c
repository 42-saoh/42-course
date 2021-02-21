/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:32 by saoh              #+#    #+#             */
/*   Updated: 2021/02/21 22:06:19 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data)
{
	int			w;
	int			h;
	int			next;
	char		*dest;

	w = 0;
	while (w < img_data->width)
	{
		h = 0;
		while (h < img_data->height)
		{
			next = (img_data->height - h - 1) * mlx_data->line_length;
			next += w * (mlx_data->bits_per_pixel / 8);
			dest = mlx_data->addr + next;
			*(unsigned int *)dest = img_data->img[w][h];
			h++;
		}
		w++;
	}
}

int				exit_program(void)
{
	exit(0);
	return (0);
}

int				mlx_key_handle(int keycode)
{
	if (keycode == 53)
		return (exit_program());
	return (0);
}

void			mlx_show(t_img_data *data, char *title)
{
	t_vars		vars;
	t_mlx_data	*img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->width, data->height, title);
	img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	img->img = mlx_new_image(vars.mlx, data->width, data->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	mlx_draw_by_img_data(img, data);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_destroy_image(vars.mlx, img->img);
	mlx_hook(vars.win, 2, 1L << 0, mlx_key_handle, 0);
	mlx_hook(vars.win, 17, 1L << 17, exit_program, 0);
	mlx_loop(vars.mlx);
	free(img);
}
