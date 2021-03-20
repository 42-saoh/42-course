/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:03:50 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 14:57:18 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light				*init_light(t_vec *ori, double intensity, t_vec *color)
{
	t_light			*result;

	result = (t_light *)malloc(sizeof(t_light));
	result->ori = ori;
	result->intensity = intensity;
	result->color = color;
	return (result);
}

t_light_info		*init_light_info(t_light *light, t_vec *p)
{
	t_light_info	*result;
	double			tmp;

	result = (t_light_info *)malloc(sizeof(t_light_info));
	result->dir = vec_sub(p, light->ori);
	tmp = vec_dot(result->dir, result->dir);
	result->length = sqrt(tmp);
	result->dir = vec_unit_apply(result->dir);
	result->intensity = vec_div_const_apply(vec_mul_const(light->color,
				light->intensity), (4 * M_PI * tmp));
	return (result);
}

void				free_light_info(t_light_info *l_info)
{
	free(l_info->dir);
	free(l_info->intensity);
	free(l_info);
}

void				free_light(t_light *l)
{
	free(l->ori);
	free(l->color);
	free(l);
}
