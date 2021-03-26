/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_ambient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:01:28 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:43:04 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_ambient_error(char *line, t_num num)
{
	if (*line != 0)
		return (1);
	if (num.val1 > 1 || num.val1 < 0)
		return (1);
	if (num.val2 > 255 || num.val2 < 0)
		return (1);
	if (num.val3 > 255 || num.val3 < 0)
		return (1);
	if (num.val4 > 255 || num.val4 < 0)
		return (1);
	return (0);
}

void			set_ambient(char *line, t_rt *rt, t_overlap *ol)
{
	t_num		num;

	ol->a_ol = 1;
	line = cut_space(line, rt);
	line = get_double(line, &(num.val1), rt);
	line = cut_space(line, rt);
	line = get_double(line, &(num.val2), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val3), rt);
	line = is_comma(line, rt);
	line = get_double(line, &(num.val4), rt);
	line = cut_space2(line);
	if (rt->is_error || check_ambient_error(line, num))
		rt->is_error = 1;
	else
		rt->am = init_ambient(num.val1,
				vec_create(num.val2, num.val3, num.val4));
}
