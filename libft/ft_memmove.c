/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:31:23 by saoh              #+#    #+#             */
/*   Updated: 2020/10/09 18:47:50 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	clone[n];

	i = 0;
	if (dest == 0 && src == 0)
	{
		dest = 0;
		return (dest);
	}
	while (i < n)
	{
		clone[i] = *((char *)src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = clone[i];
		i++;
	}
	return (dest);
}
