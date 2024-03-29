/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:03:43 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 14:56:50 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double				clamp(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

double				get_radian(double degree)
{
	return (degree * M_PI / 180.0);
}
