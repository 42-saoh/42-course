/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:20:56 by saoh              #+#    #+#             */
/*   Updated: 2020/10/12 13:49:54 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && (*((char *)ptr1 + i) || *((char *)ptr2 + i)))
	{
		if (*((unsigned char *)ptr1 + i) > (*((unsigned char *)ptr2 + i)))
			return (1);
		else if (*((unsigned char *)ptr1 + i) < (*((unsigned char *)ptr2 + i)))
			return (-1);
		else
			i++;
	}
	return (0);
}
