#include "pipex.h"
#include <stdio.h>

void	heredoc_write(int tmp_fd, char *limiter)
{
	char buf[1000];
	int	ret;
	int	i;

	ret = 1;
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
			write(tmp_fd, buf, ret);
		else
			ret = 0;
	}
}
