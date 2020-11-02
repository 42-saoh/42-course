/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/11/02 12:54:43 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		chr_buf(char **buff, char *chr_buff, char **line)
{
	char	*t_buff;

	*line = ft_substr(*buff, 0, chr_buff - *buff);
	if (*(chr_buff + 1) != 0)
	{
		t_buff = ft_strdup(chr_buff + 1);
		free(*buff);
		*buff = t_buff;
	}
	else
	{
		free(*buff);
		*buff = 0;
	}
	return (1);
}

int		chr_nul(char **buff, char **line)
{
	char	*chr_buff;

	if (*buff == NULL)
		*buff = ft_strdup("");
	else if ((chr_buff = ft_strchr(*buff, '\n')) != NULL)
		return (chr_buf(buff, chr_buff, line));
	*line = *buff;
	*buff = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buff[OPEN_MAX + 2];
	char			rd_str[BUFFER_SIZE + 1];
	char			*chr_buff;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, rd_str, BUFFER_SIZE)) > 0)
	{
		rd_str[ret] = 0;
		buff[fd] = ft_strjoin(buff[fd], rd_str);
		if ((chr_buff = ft_strchr(buff[fd], '\n')) != NULL)
			return (chr_buf(&buff[fd], chr_buff, line));
	}
	if (ret < 0)
		return (-1);
	return (chr_nul(&buff[fd], line));
}
