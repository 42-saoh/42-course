/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:50:47 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 14:57:39 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			*vec_random_range(double min, double max)
{
	return (vec_create(random_double_range(min, max), random_double_range(min,
					max), random_double_range(min, max)));
}

t_vec			*vec_random_in_unit_sphere(void)
{
	t_vec		*result;

	while (1)
	{
		result = vec_random_range(-1, 1);
		if (vec_length_squared(result) >= 1)
		{
			free(result);
			continue ;
		}
		return (result);
	}
}

t_vec			*vec_random_unit(void)
{
	double		a;
	double		cos_b;
	double		sin_b;

	a = random_double_range(0, 2 * M_PI);
	cos_b = random_double_range(-1, 1);
	sin_b = sqrt(1.0 - cos_b * cos_b);
	return (vec_create(sin_b * cos(a), sin_b * sin(a), cos_b));
}

t_vec			*vec_random_in_hemisphere(t_vec *normal)
{
	t_vec		*in_unit;

	in_unit = vec_random_unit();
	if (vec_dot(in_unit, normal) > 0.0)
		return (in_unit);
	return (vec_mul_const_apply(in_unit, -1.0));
}
