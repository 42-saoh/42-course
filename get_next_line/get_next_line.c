/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/10/30 15:35:52 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*buff;
	char			*rd_str;
	char			*chr_buff;
	char			*t_buff;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rd_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ret = read(fd, rd_str, BUFFER_SIZE)) >= 0)
	{
		rd_str[ret] = 0;
		if (buff == NULL && ret != 0)
			buff = ft_strdup(rd_str);
		else if (buff != NULL && ret != 0)
			buff = ft_strjoin(buff, rd_str);
		if ((chr_buff = ft_strchr(buff, '\n')) != NULL)
		{
			*line = ft_substr(buff, 0, chr_buff - buff);
			if (chr_buff + 1 != 0)
			{
				t_buff = ft_strdup(chr_buff + 1);
				free(buff);
				buff = t_buff;
			}
			if (ret == 0)
				return (0);
			return (1);
		}
		else if (chr_buff == NULL && ret == 0)
		{
			*line = ft_strdup(buff);
			free(buff);
			return (0);
		}
	}
	return (-1);
}
