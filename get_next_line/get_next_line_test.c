/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/10/27 20:52:17 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *buff = NULL;
	char		*rd_str;
	char		*t_str;
	char		*s_str;
	int			a;

	if (!(rd_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((a = read(fd, rd_str, BUFFER_SIZE)) == 0)
	{
		free(rd_str);
		return (0);
	}
	rd_str[a] = 0;
	if (buff == NULL)
		buff = ft_strdup("");
	if ((t_str = ft_strchr(rd_str, '\n')) != NULL)
	{
		s_str = ft_substr(rd_str, 0, t_str - rd_str)
		*line = ft_strjoin(buff, s_str)
		free(buff);
		if (*(t_str + 1) != 0)
			buff = ft_strdup(t_str + 1);
	}
	else
	{
		s_str = ft_strdup(buff);
		free(buff);
		buff = ft_strjoin(s_str, rd_str)) == NULL)
	}
	free(s_str);
	free(rd_str);
	return (1);
}
