/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:46:51 by saoh              #+#    #+#             */
/*   Updated: 2020/10/07 18:30:24 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (n == 0)
		return (src_len);
	while (i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}
