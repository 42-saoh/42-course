/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:25:02 by saoh              #+#    #+#             */
/*   Updated: 2020/10/24 14:20:19 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dest, int val, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*((unsigned char *)dest + i) = (unsigned char)val;
		i++;
	}
	return (dest);
}
