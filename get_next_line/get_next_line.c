/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/10/28 14:39:52 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(char *rd_str, int fd)
{
	int a;

	if ((a = read(fd, rd_str, BUFFER_SIZE + 1)) == 0)
		return (0);
	rd_str[a] = 0;
	return (1);
}

void	*ft_put_str(char *rd_str, char *buff, char **line)
{
	char *t_str;
	char *s_str;

	if (buff == NULL)
		buff = ft_strdup("");
	if ((t_str = ft_strchr(rd_str, '\n')) != NULL)
	{
		s_str = ft_substr(rd_str, 0, t_str - rd_str);
		*line = ft_strjoin(buff, s_str);
		free(buff);
		if ((t_str + 1) != NULL)
			buff = ft_strdup(t_str + 1);
	}
	else
	{
		s_str = ft_strdup(buff);
		free(buff);
		buff = ft_strjoin(s_str, rd_str);
	}
	free(s_str);
	return (buff);
}

void	*ft_put_buff(char *buff, char **line)
{
	char *t_buff;
	char *s_buff;

	if (buff == NULL)
		return (NULL);
	s_buff = ft_strdup(buff);
	if ((t_buff = ft_strchr(s_buff, '\n')) != NULL)
	{
		*line = ft_substr(buff, 0, t_buff - s_buff);
		free(buff);
		if ((t_buff + 1) != NULL)
			buff = ft_strdup(t_buff + 1);
	}
	else
	{
		*line = ft_strdup(buff);
		free(buff);
	}
	free(s_buff);
	return (buff);
}

int		get_next_line(int fd, char **line)
{
	static char *buff = NULL;
	char		*rd_str;
	int			a;

	if (line == NULL)
		return (-1);
	if (!(rd_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((a = ft_read(rd_str, fd)) == -1)
		return (a);
	if (a == 0)
		buff = ft_put_buff(buff, line);
	else
		buff = ft_put_str(rd_str, buff, line);
	free(rd_str);
	return (a);
}
