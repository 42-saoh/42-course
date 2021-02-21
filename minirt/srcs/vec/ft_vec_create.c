/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:50:23 by saoh              #+#    #+#             */
/*   Updated: 2021/02/21 21:50:24 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			*vec_create(double x, double y, double z)
{
	t_vec		*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_vec			*vec_dup(t_vec *ori)
{
	return (vec_create(ori->x, ori->y, ori->z));
}
