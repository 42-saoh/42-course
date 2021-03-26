/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:23:11 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_cylinder_error(char *line, t_num *num)
{
	if (line == NULL || *line != 0)
		return (1);
	if (num->val4 > 1 && num->val4 < -1)
		return (1);
	if (num->val5 > 1 && num->val5 < -1)
		return (1);
	if (num->val6 > 1 && num->val6 < -1)
		return (1);
	if (num->val9 > 255 && num->val9 < 0)
		return (1);
	if (num->val10 > 255 && num->val10 < 0)
		return (1);
	if (num->val11 > 255 && num->val11 < 0)
		return (1);
	return (0);
}

void			set_cylinder2(char *line, t_rt *rt, t_num *num)
{
	t_cylinder	*cy;

	line = get_double(line, &(num->val9));
	line = is_comma(line);
	line = get_double(line, &(num->val10));
	line = is_comma(line);
	line = get_double(line, &(num->val11));
	line = cut_space(line);
	if (check_cylinder_error(line, num))
		rt->is_error = 1;
	else
	{
		cy = init_cylinder(vec_create(num->val1, num->val2, num->val3),
				vec_create(num->val4, num->val5, num->val6), num->val7,
				num->val8, vec_create(num->val9, num->val10, num->val11));
		hitlst_add(rt->lst, (void *)cy, OBJ_CYLINDER);
	}
}

void			set_cylinder(char *line, t_rt *rt)
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
	line = get_double(line, &(num.val8));
	line = cut_space(line);
	set_cylinder2(line, rt, &num);
}
