/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:41:00 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 17:16:51 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					check_rt_lst(t_rt *rt)
{
	if (rt->img == NULL || rt->c_lst->content == NULL || rt->am == NULL
			|| rt->lst->content == NULL || rt->l_lst->content == NULL)
	{
		free_lsts(rt);
		return (0);
	}
	return (1);
}

int					check_file_name(char *name)
{
	size_t			i;

	i = ft_strlen(name);
	if (name[i - 3] != '.')
		return (error_input());
	if (name[i - 2] != 'r')
		return (error_input());
	if (name[i - 1] != 't')
		return (error_input());
	return (1);
}

int					check_rt(char *f_name, t_rt *rt)
{
	int				fd;

	if (!check_file_name(f_name))
		return (0);
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		return (error_input());
	if (!parsing_rt(fd, rt))
		return (0);
	close(fd);
	return (1);
}

int					check_issave(char *s, t_rt *rt)
{
	char			*save = "--save";

	while (*s && *save)
	{
		if (*s != *save)
			return (error_input());
		s++;
		save++;
	}
	if (*s != *save || *s != 0 || *save != 0)
		return (error_input());
	rt->is_save = 1;
	return (1);
}
