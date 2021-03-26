/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:45:03 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_sphere_error(char *line, t_num *num)
{
	if (*line != 0)
		return (1);
	if (num->val5 > 255 || num->val5 < 0)
		return (1);
	if (num->val6 > 255 || num->val6 < 0)
		return (1);
	if (num->val7 > 255 || num->val7 < 0)
		return (1);
	return (0);
}

void			set_sphere2(t_rt *rt, t_num *num)
{
	t_sphere	*s;

	s = init_sphere(vec_create(num->val1, num->val2, num->val3), num->val4,
			vec_create(num->val5, num->val6, num->val7));
	hitlst_add(rt->lst, (void *)s, OBJ_SPHERE);
}

void			set_sphere(char *line, t_rt *rt)
{
	t_num		num;

	line = cut_space(line, rt);
	line = get_double(line, &(num.val1), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val2), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val3), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val4), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val5), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val6), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val7), rt);
	line = cut_space2(line);
	if (rt->is_error || check_sphere_error(line, &num))
		rt->is_error = 1;
	else
		set_sphere2(rt, &num);
}
