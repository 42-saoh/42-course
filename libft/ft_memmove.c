/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:31:23 by saoh              #+#    #+#             */
/*   Updated: 2020/10/12 18:49:26 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c_dest;
	unsigned char		*c_src;

	if (dest == src || n == 0)
		return (dest);
	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(c_dest + i) = *(c_src + i);
			i++;
		}
	}
	else
	{
		i = n + 1;
		while (i--)
			*(c_dest + (i - 1)) = *(c_src + (i - 1));
	}
	return (dest);
}
