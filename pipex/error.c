#include "pipex.h"

int	error_occur(int i)
{
	char *error;

	if (i == 1)
	{
		error = strerror(errno);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
	else if (i == 2)
		write(2, "path or memory error\n", 21);
	return (1);
}

char	**split_error(char **paths)
{
	int	i;

	i = 0;
	while(paths[i])
	{
		free(paths[i]);
		i++;
	}
	return (NULL);
}

int	error_print(int i)
{
	if (i == 1)
		write(1, "fork error\n", 11);
	else if (i == 2)
		write(1, "fd error\n", 9);
	else if (i == 3)
		write(1, "parsing error\n", 14);
	else if (i == 4)
		write(1, "pipe error\n", 11);
	return (1);
}

void	fail_execve(t_pipe *tp)
{
	char *str;

	str = tp->cmd[0];
	write(2, "zsh : command not found: ", 25);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
