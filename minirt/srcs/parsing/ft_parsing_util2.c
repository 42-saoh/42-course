/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:57:21 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:48:50 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*cut_space(char *line, t_rt *rt)
{
	if (*line == 0)
		return (line);
	if (*line != ' ')
	{
		rt->is_error = 1;
		return (line);
	}
	while (*line == ' ')
		line++;
	return (line);
}

char			*cut_space2(char *line)
{
	if (*line == 0)
		return (line);
	while (*line == ' ')
		line++;
	return (line);
}

void			free_lsts(t_rt *rt)
{
	if (rt->lst != NULL)
		free_hitlst(rt->lst);
	if (rt->l_lst != NULL)
		free_hitlst(rt->l_lst);
	if (rt->c_lst != NULL)
		free_hitlst(rt->c_lst);
	if (rt->img != NULL)
		free_img_data(rt->img);
	if (rt->am != NULL)
		free_ambient(rt->am);
}
