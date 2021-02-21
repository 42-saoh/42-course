/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:44 by saoh              #+#    #+#             */
/*   Updated: 2021/02/21 22:04:45 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double		random_double_range(double min, double max)
{
	return (min + (max - min) * random_double());
}
