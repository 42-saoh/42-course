#include "pipex.h"

int	wait_status(int status)
{
	return (status & 0177);
}

int	wait_exit_status(int status)
{
	return ((status >> 8) & 0x000000ff);
}
