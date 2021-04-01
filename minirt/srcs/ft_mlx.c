/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:32 by saoh              #+#    #+#             */
/*   Updated: 2021/04/01 17:27:58 by saoh             ###   ########.fr       */
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

int				exit_program(t_rt *rt)
{
	mlx_destroy_image(rt->vars->mlx, rt->mlx->img);
	exit(0);
	return (0);
}

int				mlx_key_handle(int keycode, t_rt *rt)
{
	t_hittable	*hittable;
	t_camera	*t_cam;

	if (keycode == 53)
		return (exit_program(rt));
	if (keycode == 124)
	{
		if (rt->c_lst->next)
			rt->c_lst = rt->c_lst->next;
		else
			rt->c_lst = rt->t_lst;
		hittable = (t_hittable *)rt->c_lst->content;
		t_cam = (t_camera *)hittable->obj;
		mlx_draw_by_img_data(rt->mlx, t_cam->data);
		mlx_put_image_to_window(rt->vars->mlx, rt->vars->win,
				rt->mlx->img, 0, 0);
	}
	return (0);
}

void			mlx_show(t_img_data *data, char *title, t_rt *rt)
{
	t_vars		vars;
	t_mlx_data	*img;

	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &vars.max_w, &vars.max_h);
	if (data->width > vars.max_w)
		data->width = vars.max_w;
	if (data->height > vars.max_h)
		data->height = vars.max_h;
	vars.win = mlx_new_window(vars.mlx, data->width, data->height, title);
	img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	img->img = mlx_new_image(vars.mlx, data->width, data->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	rt->mlx = img;
	rt->vars = &vars;
	mlx_draw_by_img_data(img, data);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, mlx_key_handle, rt);
	mlx_hook(vars.win, 17, 1L << 17, exit_program, rt);
	mlx_loop(vars.mlx);
	free(img);
}
