/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:55:50 by saoh              #+#    #+#             */
/*   Updated: 2021/10/13 14:32:13 by saoh             ###   ########.fr       */
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

void	parsing_and_check_cmd(t_pipe *tp, char *line)
{
	char	*full_path;
	int		i;

	tp->cmd = ft_split(line, ' ');
	if (!tp->cmd)
		error_print(3);
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
		return ;
	free(tp->cmd[0]);
	tp->cmd[0] = full_path;
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

void	parent_get_status(t_pipe *tp, int cnt)
{
	int	status;
	int	tmp;

	tmp = waitpid(-1, &status, WNOHANG);
	while (tmp == -1 && errno == EINTR)
		tmp = wait(&status);
	if (tmp == -1)
		error_print(5);
	tp->exec_result = wait_exit_status(status);
	tmp = wait_status(status);
	if (tmp)
		tp->exec_result = 128 + tmp;
	if (reset_pipe(tp, cnt))
		error_print(4);
}

void	start_pipe(t_pipe *tp, char **argv, char **envp, int cnt)
{
	tp->pid[cnt] = fork();
	if (tp->pid[cnt] < 0)
		error_print(1);
	if (tp->pid[cnt] == 0)
	{
		if (apply_fd(tp, cnt))
			error_print(2);
		close_fd(tp, cnt);
		if (tp->heredoc_flag)
			parsing_and_check_cmd(tp, argv[cnt + 3]);
		else
			parsing_and_check_cmd(tp, argv[cnt + 2]);
		execve(tp->cmd[0], tp->cmd, envp);
		fail_execve(tp);
		exit(127);
	}
	else
		parent_get_status(tp, cnt);
}
