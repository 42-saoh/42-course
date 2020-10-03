/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:46:12 by saoh              #+#    #+#             */
/*   Updated: 2020/10/03 20:51:44 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!(substr = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[i + start - 1];
		i++;
	}
	return (substr);
}
