#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

char	*get_name(int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) + 5);
	result[0] = 'e';
	result[1] = n / 100 + '0';
	result[2] = ((n % 100) / 10) + '0';
	result[3] = (n % 10) + '0';
	result[4] = 0;
	return (result);
}

int main()
{
	char	*name;
	int		i;
	int		c;

	c = sem_unlink("forks");
	printf("forks : %d, %s\n", c, strerror(errno));
	i = 0;
	while (i < 201)
	{
		name = get_name(i);
		c = sem_unlink(name);
		printf("%d : %d, %s\n", i, c, strerror(errno));
		free(name);
		name = 0;
		i++;
	}
}
