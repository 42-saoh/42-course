/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:15:47 by saoh              #+#    #+#             */
/*   Updated: 2021/10/03 15:18:44 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_pipe
{
	int pipe_fd[2];
	int pipe_tmp_fd[2];
	int	in_fd;
	int	out_fd;
	int	cnt_cut;
	char	**paths;
	char	**cmd;
	pid_t	pid;
}				t_pipe;

void	ft_memset(void *address, int size);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		init_path(t_pipe *tp, char **envp);
int		error_occur(int i);
int		error_print(int i);
char	**split_error(char **paths);
char	*ft_substr(char *path, int s, int e);
int		start_pipe(t_pipe *tp, char **argv, char **envp, int cnt);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_split(char *path, char symbol);
void	fail_execve(t_pipe *tp);

#endif
