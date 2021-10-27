/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:22 by saoh              #+#    #+#             */
/*   Updated: 2021/10/13 14:33:31 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc_write(int tmp_fd, char *limiter, int ret)
{
	char	buf[1000];
	int		i;

	while (ret)
	{
		ret = read(0, buf, 1000);
		buf[ret - 1] = 0;
		i = 0;
		while (limiter[i])
		{
			if (limiter[i] == buf[i])
				i++;
			else
				break ;
		}
		if (limiter[i] || buf[i])
		{
			buf[ret - 1] = '\n';
			buf[ret] = 0;
			write(tmp_fd, buf, ret);
		}
		else
			ret = 0;
	}
}
