/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/03/03 15:37:58 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triangle		*init_triangle(t_vec *v0, t_vec *v1, t_vec *v2)
{
	t_triangle	*result;
	t_vec		*tmp1;
	t_vec		*tmp2;

	result = (t_triangle *)malloc(sizeof(t_triangle));
	result->v0 = v0;
	result->v1 = v1;
	result->v2 = v2;
	tmp1 = vec_sub(v1, v0);
	tmp2 = vec_sub(v2, v0);
	result->normal = vec_unit_apply(vec_cross(tmp1, tmp2));
	free(tmp1);
	free(tmp2);
	return (result);
}

void			free_triangle(t_triangle *tr)
{
	free(tr->v0);
	free(tr->v1);
	free(tr->v2);
	free(tr->normal);
	free(tr);
}
