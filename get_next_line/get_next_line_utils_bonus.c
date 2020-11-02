/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:53 by saoh              #+#    #+#             */
/*   Updated: 2020/11/02 13:53:05 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char		*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (NULL);
}

char		*ft_strdup(const char *str)
{
	char	*clone;
	size_t	i;

	if (!(clone = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		clone[i] = str[i];
		i++;
	}
	clone[i] = 0;
	return (clone);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (s1 == NULL ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= s2_len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	free(s1);
	return (str);
}

char		*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	if (str == NULL)
	{
		substr = 0;
		return (substr);
	}
	str_len = ft_strlen(str);
	if (str_len <= (size_t)start)
		return (ft_strdup(""));
	else if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && i + start < str_len)
	{
		substr[i] = str[i + start];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
