/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:01:39 by saoh              #+#    #+#             */
/*   Updated: 2020/10/08 14:58:52 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
