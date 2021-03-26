/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:58:00 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:27:20 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		set_rt(t_rt *rt)
{
	rt->is_save = 0;
	rt->lst = NULL;
	rt->l_lst = NULL;
	rt->cam = NULL;
	rt->img = NULL;
	rt->am = NULL;
}

void		free_rt(t_rt *rt)
{
	free_hitlst(rt->lst);
	free_hitlst(rt->l_lst);
	free_camera(rt->cam);
	free_img_data(rt->img);
	free_ambient(rt->am);
}

int 		main(int argc, char *argv[])
{
	t_rt	rt;

	set_rt(&rt);
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
			if (!check_issave(argv[2], &rt))
				return (0);
		if (!check_rt(argv[1], &rt))
			return (0);
	}
	else
		return (error_input());
	if (!check_rt_lst(&rt))
		return (error_file());
	draw_hittable_pthread(rt.cam, rt.lst, rt.l_lst);
	if (rt.is_save)
		save_bmp((rt.cam)->data, argv[1]);
	else
		mlx_show((rt.cam)->data, argv[1]);
	free_rt(&rt);
	return (0);
}
