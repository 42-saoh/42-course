/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/10/30 19:48:46 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		chr_buf(char *buff, char *chr_buff, char **line, int ret)
{
	char	*t_buff;

	if (*(chr_buff + 1) != 0)
	{
		*line = ft_substr(buff, 0, chr_buff - buff);
		t_buff = ft_strdup(chr_buff + 1);
		free(buff);
		buff = t_buff;
	}
	else
	{
		*line = ft_substr(buff, 0, chr_buff - buff);
		free(buff);
		buff = 0;
	}
	if (ret == 0)
		return (0);
	return (1);
}

int		chr_nul(char *buff, char **line)
{
	*line = buff;
	buff = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buff = 0;
	char			rd_str[BUFFER_SIZE + 1];
	char			*chr_buff;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, rd_str, BUFFER_SIZE)) >= 0)
	{
		rd_str[ret] = 0;
		if (buff == 0 && ret != 0)
			buff = ft_strdup(rd_str);
		else if (buff != 0 && ret != 0)
			buff = ft_strjoin(buff, rd_str);
		if ((chr_buff = ft_strchr(buff, '\n')) != NULL)
			return (chr_buf(buff, chr_buff, line, ret));
		else if (chr_buff == NULL && ret == 0)
			return (chr_nul(buff, line));
	}
	return (-1);
}
