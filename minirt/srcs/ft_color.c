/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:03:50 by saoh              #+#    #+#             */
/*   Updated: 2021/03/19 16:00:36 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int			get_color_val(t_vec *color)
{
	int		x;
	int		y;
	int		z;

	x = clamp(color->x, 0.0, 0.999) * 256.0;
	y = clamp(color->y, 0.0, 0.999) * 256.0;
	z = clamp(color->z, 0.0, 0.999) * 256.0;
	return (x << 16 | y << 8 | z);
}

t_vec		*get_color(int rgb)
{
	t_vec	*result;

	result = (t_vec *)malloc(sizeof(t_vec));
	result->x = (rgb & (0xFF << 16)) >> 16;
	result->y = (rgb & (0xFF << 8)) >> 8;
	result->z = rgb & 0xFF;
	return (result);
}

void		p_v(t_vec *vec)
{
	printf("vec : %f %f %f \n", vec->x, vec->y, vec->z);
}

int			get_color_sample_gamma(t_vec *color)
{
	double	x;
	double	y;
	double	z;

	x = color->x / ANTI_SAMPLES;
	y = color->y / ANTI_SAMPLES;
	z = color->z / ANTI_SAMPLES;
	x = clamp(x, 0.0, 255);
	y = clamp(y, 0.0, 255);
	z = clamp(z, 0.0, 255);
	return ((int)x << 16 | (int)y << 8 | (int)z);
}
