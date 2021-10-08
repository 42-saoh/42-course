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
