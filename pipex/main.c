/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:28:46 by saoh              #+#    #+#             */
/*   Updated: 2021/10/07 16:11:56 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_mandatory_tp(t_pipe *tp, int argc, char **argv)
{
	tp->in_fd = open(argv[1], O_RDONLY | O_EXCL);
	if (tp->in_fd < 0)
		error_occur(1, argv[1]);
	tp->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (tp->out_fd < 0)
		error_occur(1, argv[argc - 1]);
	if (pipe(tp->pipe_fd) < 0)
		error_occur(1, NULL);
	if (pipe(tp->pipe_tmp_fd) < 0)
		error_occur(1, NULL);
	tp->cnt_cut = argc - 4;
}

int	check_heredoc(char *str)
{
	char	*here_doc;
	int		i;

	here_doc = "here_doc";
	i = 0;
	while (str[i])
	{
		if (str[i] == here_doc[i])
			i++;
		else
			break ;
	}
	if (str[i] || here_doc[i])
		return (0);
	return (1);
}

void	init_heredoc_tp(t_pipe *tp, int argc, char **argv)
{
	int	tmp_fd;

	if (argc != 6)
		argument_error();
	tmp_fd = open("tmp_heredoc", O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (tmp_fd < 0)
		error_occur(1, argv[1]);
	heredoc_write(tmp_fd, argv[2], 1);
	close(tmp_fd);
	tp->in_fd = open("tmp_heredoc", O_RDONLY, 00644);
	if (tp->in_fd < 0)
		error_occur(1, argv[1]);
	tp->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (tp->out_fd < 0)
		error_occur(1, argv[argc - 1]);
	if (pipe(tp->pipe_fd) < 0)
		error_occur(1, NULL);
	if (pipe(tp->pipe_tmp_fd) < 0)
		error_occur(1, NULL);
	tp->cnt_cut = argc - 5;
	tp->heredoc_flag = 1;
}

void	end_tp(t_pipe *tp)
{
	int	i;

	close(tp->in_fd);
	close(tp->out_fd);
	i = 0;
	if (tp->cmd)
	{
		while (tp->cmd[i])
		{
			free(tp->cmd[i]);
			i++;
		}
		free(tp->cmd);
		i = 0;
	}
	if (tp->paths)
	{
		while (tp->paths[i])
		{
			free(tp->paths[i]);
			i++;
		}
		free(tp->paths);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	tp;
	int		cnt;

	if (argc < 5)
		argument_error();
	ft_memset(&tp, sizeof(t_pipe));
	init_path(&tp, envp);
	if (check_heredoc(argv[1]))
		init_heredoc_tp(&tp, argc, argv);
	else
		init_mandatory_tp(&tp, argc, argv);
	cnt = 0;
	while (cnt <= tp.cnt_cut)
	{
		start_pipe(&tp, argv, envp, cnt);
		cnt++;
	}
	cnt = tp.exec_result;
	end_tp(&tp);
	if (tp.heredoc_flag)
		unlink("tmp_heredoc");
	return (cnt);
}
