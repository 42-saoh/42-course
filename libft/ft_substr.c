/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:46:12 by saoh              #+#    #+#             */
/*   Updated: 2020/10/18 18:32:15 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
