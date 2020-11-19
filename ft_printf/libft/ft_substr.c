/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:46:12 by saoh              #+#    #+#             */
/*   Updated: 2020/11/19 19:29:37 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len <= (size_t)start || len == 0)
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
