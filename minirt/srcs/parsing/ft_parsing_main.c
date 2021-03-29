/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:41:00 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 15:24:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				set_ol_rt_lst(t_overlap *ol, int *is_read, t_rt *rt)
{
	*is_read = 1;
	ol->r_ol = 0;
	ol->a_ol = 0;
	rt->is_error = 0;
	rt->lst = hitlst_new();
	rt->l_lst = hitlst_new();
	rt->c_lst = hitlst_new();
}

void				parsing_line(char *line, t_rt *rt, t_overlap *ol)
{
	if (line == 0 || *line == 0)
		return ;
	else if (*line == 'R' && *(line + 1) == ' ' && !(ol->r_ol))
		set_image(line + 1, rt, ol);
	else if (*line == 'A' && *(line + 1) == ' ' && !(ol->a_ol))
		set_ambient(line + 1, rt, ol);
	else if (*line == 'c' && *(line + 1) == ' ')
		set_camera(line + 1, rt);
	else if (*line == 'l' && *(line + 1) == ' ')
		set_light(line + 1, rt);
	else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
		set_plane(line + 2, rt);
	else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
		set_sphere(line + 2, rt);
	else if (*line == 's' && *(line + 1) == 'q' && *(line + 2) == ' ')
		set_square(line + 2, rt);
	else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
		set_cylinder(line + 2, rt);
	else if (*line == 't' && *(line + 1) == 'r' && *(line + 2) == ' ')
		set_triangle(line + 2, rt);
	else
		rt->is_error = 1;
}

int					parsing_rt(int fd, t_rt *rt)
{
	char			*line;
	int				is_read;
	t_overlap		ol;

	set_ol_rt_lst(&ol, &is_read, rt);
	while (is_read)
	{
		line = 0;
		is_read = get_next_line(fd, &line);
		if (is_read < 0)
		{
			close(fd);
			free_lsts(rt);
			return (error_file());
		}
		parsing_line(line, rt, &ol);
		free(line);
		if (rt->is_error)
		{
			close(fd);
			free_lsts(rt);
			return (error_file());
		}
	}
	return (1);
}
