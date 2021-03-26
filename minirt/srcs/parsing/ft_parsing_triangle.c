/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:45:52 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_triangle_error(char *line, t_num *num)
{
	if (*line != 0)
		return (1);
	if (num->val10 > 255 || num->val10 < 0)
		return (1);
	if (num->val11 > 255 || num->val11 < 0)
		return (1);
	if (num->val12 > 255 || num->val12 < 0)
		return (1);
	return (0);
}

void			set_triangle2(char *line, t_rt *rt, t_num *num)
{
	t_triangle	*tr;

	line = get_double(line, &(num->val10), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num->val11), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num->val12), rt);
	line = cut_space2(line);
	if (rt->is_error || check_triangle_error(line, num))
		rt->is_error = 1;
	else
	{
		tr = init_triangle(vec_create(num->val1, num->val2, num->val3),
				vec_create(num->val4, num->val5, num->val6),
				vec_create(num->val7, num->val8, num->val9),
				vec_create(num->val10, num->val11, num->val12));
		hitlst_add(rt->lst, (void *)tr, OBJ_TRIANGLE);
	}
}

void			set_triangle(char *line, t_rt *rt)
{
	t_num		num;

	line = cut_space(line,rt);
	line = get_double(line, &(num.val1), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val2), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val3), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val4), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val5), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val6), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val7), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val8), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val9), rt);
	line = cut_space(line, rt);
	set_triangle2(line, rt, &num);
}
