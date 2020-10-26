/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:06:55 by saoh              #+#    #+#             */
/*   Updated: 2020/10/26 16:43:45 by saoh             ###   ########.fr       */
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
