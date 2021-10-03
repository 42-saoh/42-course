/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:55:50 by saoh              #+#    #+#             */
/*   Updated: 2021/10/03 15:55:51 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	apply_fd(t_pipe *tp, int cnt)
{
	if (cnt == 0)
	{
		if (dup2(tp->in_fd, 0) == -1)
			return (1);
		if (dup2(tp->pipe_fd[1], 1) == -1)
			return (1);
	}
	else if (cnt == tp->cnt_cut)
	{
		if (dup2(tp->out_fd, 1) == -1)
			return (1);
		if (dup2(tp->pipe_fd[0], 0) == -1)
			return (1);
	}
	else
	{
		if (dup2(tp->pipe_fd[0], 0) == -1)
			return (1);
		if (dup2(tp->pipe_fd[1], 1) == -1)
			return (1);
	}
	return (0);
}

int	parsing_and_check_cmd(t_pipe *tp, char *line)
{
	char	*full_path;
	int		i;

	tp->cmd = ft_split(line, ' ');
	if (!tp->cmd)
		return (1);
	i = 0;
	while (tp->paths[i])
	{
		full_path = ft_strjoin(tp->paths[i], tp->cmd[0]);
		if (!access(full_path, F_OK))
			break ;
		free(full_path);
		full_path = 0;
		i++;
	}
	if (!tp->paths[i])
		return (0);
	free(tp->cmd[0]);
	tp->cmd[0] = full_path;
	return (0);
}

int	reset_pipe(t_pipe *tp, int cnt)
{
	if (cnt == 0)
	{
		close(tp->pipe_fd[1]);
		tp->pipe_fd[1] = tp->pipe_tmp_fd[1];
	}
	else if (cnt == tp->cnt_cut)
	{
		close(tp->pipe_fd[1]);
		close(tp->pipe_fd[0]);
		close(tp->pipe_tmp_fd[0]);
	}
	else
	{
		close(tp->pipe_fd[1]);
		close(tp->pipe_fd[0]);
		tp->pipe_fd[0] = tp->pipe_tmp_fd[0];
		if (pipe(tp->pipe_tmp_fd))
			return (1);
		tp->pipe_fd[1] = tp->pipe_tmp_fd[1];
	}
	return (0);
}

int	start_pipe(t_pipe *tp, char **argv, char **envp, int cnt)
{
	int	status;

	tp->pid = fork();
	if (tp->pid < 0)
		return (error_print(1));
	if (tp->pid == 0)
	{
		if (apply_fd(tp, cnt))
			return (error_print(2));
		if (parsing_and_check_cmd(tp, argv[cnt + 2]))
			return (error_print(3));
		execve(tp->cmd[0], tp->cmd, envp);
		fail_execve(tp);
		exit(127);
	}
	else
	{
		wait(&status);
		if (reset_pipe(tp, cnt))
			return (error_print(4));
	}
	return (0);
}
