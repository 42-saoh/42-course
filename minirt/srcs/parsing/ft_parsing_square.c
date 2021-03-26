/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:45:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_square_error(char *line, t_num *num)
{
	if (*line != 0)
		return (1);
	if (num->val4 > 1 || num->val4 < -1)
		return (1);
	if (num->val5 > 1 || num->val5 < -1)
		return (1);
	if (num->val6 > 1 || num->val6 < -1)
		return (1);
	if (num->val8 > 255 || num->val8 < 0)
		return (1);
	if (num->val9 > 255 || num->val9 < 0)
		return (1);
	if (num->val10 > 255 || num->val10 < 0)
		return (1);
	return (0);
}

void			set_square2(char *line, t_rt *rt, t_num *num)
{
	t_square	*sq;

	if (rt->is_error || check_square_error(line, num))
		rt->is_error = 1;
	else
	{
		sq = init_square(vec_create(num->val1, num->val2, num->val3),
				vec_create(num->val4, num->val5, num->val6), num->val7,
				vec_create(num->val8, num->val9, num->val10));
		hitlst_add(rt->lst, (void *)sq, OBJ_SQUARE);
	}
}

void			set_square(char *line, t_rt *rt)
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
	line = is_comma(line, rt);
	line = get_double(line, &(num.val5), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val6), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val7), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val8), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val9), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val10), rt);
	line = cut_space2(line);
	set_square2(line, rt, &num);
}
