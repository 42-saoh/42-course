/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:55:16 by saoh              #+#    #+#             */
/*   Updated: 2021/10/04 18:53:39 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_occur(int i, char *str)
{
	char	*error;

	if (i == 1)
	{
		write(2, "zsh : ", 6);
		error = strerror(errno);
		write(2, error, ft_strlen(error));
		if (str)
		{
			write(2, ": ", 2);
			write(2, str, ft_strlen(str));
		}
		write(2, "\n", 1);
	}
	else if (i == 2)
		write(2, "path or memory error\n", 21);
	exit(1);
}

char	**split_error(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	return (NULL);
}

void	error_print(int i)
{
	if (i == 1)
		write(2, "fork error\n", 11);
	else if (i == 2)
		write(2, "fd error\n", 9);
	else if (i == 3)
		write(2, "parsing error\n", 14);
	else if (i == 4)
		write(2, "pipe error\n", 11);
	else if (i == 5)
		write(2, "wait func return Error [-1] \n", 29);
	exit(1);
}

void	fail_execve(t_pipe *tp)
{
	char	*str;

	str = tp->cmd[0];
	write(2, "zsh : command not found: ", 25);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	argument_error(void)
{
	write(2, "argument error\nplz check and retry\n", 35);
	exit(1);
}
