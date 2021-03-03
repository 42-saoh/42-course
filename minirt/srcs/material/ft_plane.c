/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:56:09 by saoh              #+#    #+#             */
/*   Updated: 2021/02/28 16:09:48 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane		*init_plane(t_vec *center, t_vec *normal)
{
	t_plane	*result;

	result = (t_plane *)malloc(sizeof(t_plane));
	result->center = center;
	result->normal = normal;
	return (result);
}

void			free_plane(t_plane *p)
{
	free(p->center);
	free(p->normal);
	free(p);
}
