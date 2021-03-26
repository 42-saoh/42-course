/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:58:00 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 17:21:10 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				set_rt(t_rt *rt)
{
	rt->is_save = 0;
	rt->lst = NULL;
	rt->l_lst = NULL;
	rt->c_lst = NULL;
	rt->t_lst = NULL;
	rt->img = NULL;
	rt->am = NULL;
	rt->mlx = NULL;
	rt->vars = NULL;
}

void				free_rt(t_rt *rt)
{
	free_hitlst(rt->lst);
	free_hitlst(rt->l_lst);
	free_hitlst(rt->c_lst);
	free_img_data(rt->img);
	free_ambient(rt->am);
}

void				print_img_data(t_rt *rt, t_camera *cam, char *title)
{
	if (rt->is_save)
		save_bmp(cam->data, title);
	else
		mlx_show(cam->data, title, rt);
}

void				draw_img_data(t_rt *rt, char *title)
{
	t_list			*tmplst;
	t_hittable		*hittable;

	tmplst = rt->c_lst;
	rt->t_lst = rt->c_lst;
	while(tmplst)
	{
		hittable = (t_hittable *)(tmplst->content);
		draw_hittable_pthread(rt, (t_camera *)hittable->obj);
		tmplst = tmplst->next;
	}
	hittable = (t_hittable *)(rt->c_lst->content);
	print_img_data(rt, (t_camera *)hittable->obj, title);
}

int 				main(int argc, char *argv[])
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
	draw_img_data(&rt, argv[1]);
	free_rt(&rt);
	return (0);
}
