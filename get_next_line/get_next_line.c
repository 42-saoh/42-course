/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:09 by saoh              #+#    #+#             */
/*   Updated: 2020/10/27 18:12:06 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_read(char *rd_str, int fd)
{
	if (!(rd_str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (read(fd, rd_str, BUFF_SIZE) == 0)
	{
		free(rd_str);
		return (0);
	}
	rd_str[BUFF_SIZE] = 0;
	return (1)
}

void	ft_put_str(char *rd_str, char *buff, char **line)
{
	char *t_str;
	char *s_str;

	if ((t_str = ft_strchr(rd_str, '\n')) != NULL)
	{
		s_str = ft_substr(rd_str, 0, t_str - rd_str);
		*line = ft_strjoin(buff, s_str);
		free(buff);
		buff = ft_strdup(t_str + 1);
	}
	else
	{
		s_str = ft_strdup(buff);
		free(buff);
		buff = ft_strjoin(s_str, rd_str);
	}
	free(s_str);
	free(rd_str);
}

int		get_next_line(int fd, char **line)
{
	static char *buff = NULL;
	char		*rd_str;
	int			a;

	a = ft_read(rd_str, fd);
	if (a == -1)
		return (a);
	else if (a == 0)
		return (a);
	ft_put_str(rd_str, buff, line);
	return (a);
}
