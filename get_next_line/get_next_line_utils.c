/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:06:55 by saoh              #+#    #+#             */
/*   Updated: 2020/10/27 18:15:23 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
	{
		str = 0;
		return (str);
	}
	i = 0;
	if (!(str = (char *)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str[i + ft_strlen(s1)] = 0;
	return (str);
}

char		*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (str == NULL)
	{
		substr = 0;
		return (substr);
	}
	if (ft_strlen(str) <= (size_t)start)
		return (ft_strdup(""));
	else if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && i + start < ft_strlen(str))
	{
		substr[i] = str[i + start];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
