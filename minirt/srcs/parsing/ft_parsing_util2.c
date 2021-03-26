/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:57:21 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:13:50 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_lsts(t_rt *rt)
{
	if (rt->lst != NULL)
		free_hitlst(rt->lst);
	if (rt->l_lst != NULL)
		free_hitlst(rt->l_lst);
	if (rt->cam != NULL)
		free_camera(rt->cam);
	if (rt->img != NULL)
		free_img_data(rt->img);
	if (rt->am != NULL)
		free_ambient(rt->am);
}
