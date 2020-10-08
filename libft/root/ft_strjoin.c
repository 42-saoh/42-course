/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:57:03 by saoh              #+#    #+#             */
/*   Updated: 2020/10/08 14:57:33 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		s1_len;
	size_t		s2_len;
	char		*str;

	i = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	str[i + s1_len] = 0;
	return (str);
}
