/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:57:21 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:44:15 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			set_image(char *line, t_rt *rt, t_overlap *ol)
{
	int			num1;
	int			num2;

	ol->r_ol = 1;
	line = cut_space(line, rt);
	line = get_num(line, &num1, rt);
	line = cut_space(line, rt);
	line = get_num(line, &num2, rt);
	line = cut_space2(line);
	if (*line != 0 || rt->is_error)
		rt->is_error = 1;
	else
		rt->img = create_img_data(num1, num2);
}
