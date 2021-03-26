/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 12:28:30 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_buff(char *buff, char **line)
{
	*line = buff;
	return (1);
}

int		ft_eof_read(char *buff, char **line)
{
	char	*chr_buff;

	if (buff == NULL)
		buff = ft_strdup("");
	else if ((chr_buff = ft_strchr(buff, '\n')) != NULL)
		return (ft_put_buff(buff, line));
	*line = buff;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	char			*tmp_buff;
	char			rd_str[2];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	rd_str[1] = 0;
	buff = NULL;
	while ((ret = read(fd, rd_str, 1)) > 0)
	{
		if (rd_str[0] == '\n')
			return (ft_put_buff(buff, line));
		tmp_buff = ft_strjoin(buff, rd_str);
		free(buff);
		buff = tmp_buff;
	}
	if (ret < 0)
		return (-1);
	return (ft_eof_read(buff, line));
}
