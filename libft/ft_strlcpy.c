/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:46:51 by saoh              #+#    #+#             */
/*   Updated: 2020/10/24 15:00:02 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t src_len;

	i = 0;
	src_len = 0;
	if (src == 0)
		return (src_len);
	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	while (i < n - 1 && i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}
