/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:15:47 by saoh              #+#    #+#             */
/*   Updated: 2021/10/08 18:29:36 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipe
{
	int		pipe_fd[2];
	int		pipe_tmp_fd[2];
	int		in_fd;
	int		out_fd;
	int		cnt_cut;
	int		exec_result;
	int		heredoc_flag;
	char	**paths;
	char	**cmd;
	pid_t	*pid;
}	t_pipe;

void	ft_memset(void *address, int size);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	init_path(t_pipe *tp, char **envp);
void	error_occur(int i, char *str);
void	error_print(int i);
char	**split_error(char **paths);
char	*ft_substr(char *path, int s, int e);
void	start_pipe(t_pipe *tp, char **argv, char **envp, int cnt);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_split(char *path, char symbol);
void	fail_execve(t_pipe *tp);
int		wait_status(int status);
int		wait_exit_status(int status);
void	argument_error(void);
void	heredoc_write(int tmp_fd, char *limiter, int ret);
void	wait_process_block(t_pipe *tp);
void	close_fd(t_pipe *tp, int cnt);

#endif
