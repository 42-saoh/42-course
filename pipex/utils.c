#include "pipex.h"

void	ft_memset(void *address, int size)
{
	int i;
	char *clone;

	i = 0;
	clone = (char *)address;
	while (i < size)
	{
		clone[i] = 0;
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*c_str;

	len = ft_strlen(str);
	c_str = (char *)malloc(sizeof(char) * len + 1);
	if (!c_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		c_str[i] = str[i];
		i++;
	}
	c_str[i] = 0;
	return (c_str);
}

char	*ft_substr(char *path, int s, int e)
{
	int len;
	int	i;
	char	*result;

	len = e - s;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while(i < len)
	{
		result[i] = path[s];
		i++;
		s++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int	str1_len;
	int	str2_len;
	int	i;
	char	*result;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	result = (char *)malloc(sizeof(char) * (str1_len + str2_len + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	result[i++] = '/';
	while (*str2)
	{
		result[i] = *str2;
		i++;
		str2++;
	}
	result[i] = 0;
	return (result);
}
