#include "pipex.h"

void	wait_process_block(t_pipe *tp)
{
	int	status;
	int	tmp;

	while (1)
	{
		tmp = wait(&status);
		if (tmp == -1 && errno == ECHILD)
			return ;
		if (tmp == tp->pid[tp->cnt_cut])
		{
			tp->exec_result = wait_exit_status(status);
			tmp = wait_status(status);
			if (tmp)
				tp->exec_result = 128 + tmp;
		}
	}
}

void	close_fd(t_pipe *tp, int cnt)
{
	if (cnt == 0)
	{
		close(tp->pipe_fd[0]);
		close(tp->pipe_tmp_fd[0]);
		close(tp->pipe_tmp_fd[1]);
	}
	else if (cnt == tp->cnt_cut)
	{
		close(tp->pipe_fd[0]);
		close(tp->pipe_tmp_fd[0]);
	}
	else
	{
		close(tp->pipe_fd[0]);
		close(tp->pipe_tmp_fd[0]);
	}
}

