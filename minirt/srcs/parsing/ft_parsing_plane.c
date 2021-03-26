/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:06:38 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_plane_error(char *line, t_num *num)
{
	if (line == NULL || *line != 0)
		return (1);
	if (num->val4 > 1 && num->val4 < -1)
		return (1);
	if (num->val5 > 1 && num->val5 < -1)
		return (1);
	if (num->val6 > 1 && num->val6 < -1)
		return (1);
	if (num->val7 > 255 && num->val7 < 0)
		return (1);
	if (num->val8 > 255 && num->val8 < 0)
		return (1);
	if (num->val9 > 255 && num->val9 < 0)
		return (1);
	return (0);
}

void			set_plane2(t_rt *rt, t_num *num)
{
	t_plane		*p;

	p = init_plane(vec_create(num->val1, num->val2, num->val3),
			vec_create(num->val4, num->val5, num->val6),
			vec_create(num->val7, num->val8, num->val9));
	hitlst_add(rt->lst, (void *)p, OBJ_PLANE);
}

void			set_plane(char *line, t_rt *rt)
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
	line = is_comma(line);
	line = get_double(line, &(num.val8));
	line = is_comma(line);
	line = get_double(line, &(num.val9));
	line = cut_space(line);
	if (check_plane_error(line, &num))
		rt->is_error = 1;
	else
		set_plane2(rt, &num);
}
