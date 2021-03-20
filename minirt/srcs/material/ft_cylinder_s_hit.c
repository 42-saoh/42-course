/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_s_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:17 by saoh              #+#    #+#             */
/*   Updated: 2021/03/20 16:08:42 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				cylinder_s_hit(void *cy, t_ray *r, t_hitlst_info *info)
{
	double		cy_t;
	double		cap_t;

	cy_t = solve_cylinder_t((t_cylinder *)cy, r, info);
	cap_t = solve_cap_t((t_cylinder *)cy, r, info);
	if (cy_t == INFINITY && cap_t == INFINITY)
		return (0);
	return (1);
}
