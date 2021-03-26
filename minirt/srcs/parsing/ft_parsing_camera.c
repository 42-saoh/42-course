/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:12:56 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_camera_error(char *line, t_num *num)
{
	if (line == NULL || *line != 0)
		return (1);
	if (num->val4 > 1 && num->val4 < -1)
		return (1);
	if (num->val5 > 1 && num->val5 < -1)
		return (1);
	if (num->val6 > 1 && num->val6 < -1)
		return (1);
	if (num->val7 > 180 && num->val7 < 0)
		return (1);
	return (0);
}

void			set_camera2(t_rt *rt, t_num *num)
{
	if (rt->img == NULL)
		rt->is_error = 1;
	else
	{
		rt->cam = camera_locate_new(vec_create(num->val1, num->val2, num->val3),
				vec_create(num->val4, num->val5, num->val6),
				rt->img->aspect_ratio, get_radian(num->val7));
		rt->cam->data = dup_img_data(rt->img);
	}
}

void			set_camera(char *line, t_rt *rt)
{
	t_num		num;

	line = cut_space(line);
	line = get_double(line, &(num.val1));
	line = is_comma(line);
	line = get_double(line, &(num.val2));
	line = is_comma(line);
	line = get_double(line, &(num.val3));
	line = cut_space(line);
	line = get_double(line, &(num.val4));
	line = is_comma(line);
	line = get_double(line, &(num.val5));
	line = is_comma(line);
	line = get_double(line, &(num.val6));
	line = cut_space(line);
	line = get_double(line, &(num.val7));
	line = cut_space(line);
	if (check_camera_error(line, &num))
		rt->is_error = 1;
	else
		set_camera2(rt, &num);
}
