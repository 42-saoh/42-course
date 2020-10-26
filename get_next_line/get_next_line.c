/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/10/26 17:52:08 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	static char *buff = NULL;
	size_t		buff_len;

	buff_len = BUFF_SIZE;
	if (buff != NULL)
	{
		buff_len = ft_strlen(buff) + BUFF_SIZE;
		free(buff);
	}
	if (!(buff = (char *)malloc(sizeof(char) * (buff_len + 1))))
		return (-1);
	read(fd, buff, buff_len);
	buff[buff_len] = 0;
}
