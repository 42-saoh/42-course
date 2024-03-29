/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:51 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 15:49:19 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_thread_info		*tinfo_new(t_rt *rt, t_camera *cam, int tnum)
{
	t_thread_info	*result;

	result = (t_thread_info *)malloc(sizeof(t_thread_info));
	result->rt = rt;
	result->cam = cam;
	result->tnum = tnum;
	return (result);
}

int					tinfo_get_step(t_thread_info *info)
{
	return (info->cam->data->height / PTHREAD_CNT);
}

int					tinfo_get_y_init_value(t_thread_info *info)
{
	if (info->tnum == PTHREAD_CNT)
		return (info->cam->data->height);
	return (tinfo_get_step(info) * info->tnum);
}
