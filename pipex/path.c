/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:55:32 by saoh              #+#    #+#             */
/*   Updated: 2021/10/07 15:19:42 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	char	*path;
	int		i;

	path = "PATH=";
	while (*envp)
	{
		i = 0;
		while (path[i])
		{
			if (path[i] != (*envp)[i])
				break ;
			i++;
		}
		if (i == 5)
			break ;
		envp++;
	}
	if (!(*envp))
		return (NULL);
	return (ft_strdup(&(*envp)[5]));
}

int	get_cnt(char *path, char symbol)
{
	int	cnt;

	cnt = 0;
	while (*path)
	{
		if (*path == symbol)
		{
			while (*path == symbol)
				path++;
			cnt++;
		}
		else
			path++;
	}
	return (cnt + 1);
}

char	**ft_split_2(char **paths, char *path, char symbol)
{
	int	s;
	int	e;
	int	i;

	s = 0;
	e = 0;
	i = 0;
	while (path[e])
	{
		s = e;
		while (path[e] != symbol && path[e])
			e++;
		paths[i] = ft_substr(path, s, e);
		if (!paths[i++])
			return (split_error(paths));
		while (path[e] == symbol)
			e++;
	}
	return (paths);
}

char	**ft_split(char *path, char symbol)
{
	int		cnt;
	char	**paths;

	cnt = get_cnt(path, symbol);
	paths = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!paths)
		return (NULL);
	ft_memset(paths, sizeof(char *) * (cnt + 1));
	if (cnt == 1)
	{
		*paths = ft_strdup(path);
		return (paths);
	}
	return (ft_split_2(paths, path, symbol));
}

void	init_path(t_pipe *tp, char **envp)
{
	char	*path;

	path = get_path(envp);
	if (!path)
		error_occur(2, NULL);
	tp->paths = ft_split(path, ':');
	if (!tp->paths)
	{
		free(path);
		error_occur(2, NULL);
	}
	free(path);
}
