/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:03:50 by saoh              #+#    #+#             */
/*   Updated: 2021/03/19 18:07:11 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient			*init_ambient(double intensity, t_vec *color)
{
	t_ambient		*result;

	result = (t_ambient *)malloc(sizeof(t_ambient));
	result->intensity = intensity;
	result->color = color;
	return (result);
}

void				free_ambient(t_ambient *am)
{
	free(am->color);
	free(am);
}
