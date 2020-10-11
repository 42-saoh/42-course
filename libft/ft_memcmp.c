/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:20:56 by saoh              #+#    #+#             */
/*   Updated: 2020/10/11 19:58:01 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (*((unsigned char *)ptr1 + i) > (*((unsigned char *)ptr2 + i))
				&& (*((char *)ptr1 + i) != 0 && *((char *)ptr2 + i) == 0))
			return (1);
		else if (*((unsigned char *)ptr1 + i) < (*((unsigned char *)ptr2 + i))
				&& (*((char *)ptr1 + i) == 0 && *((char *)ptr2 + i) != 0))
			return (-1);
		else if ((*((char *)ptr1 + i) == 0)
				&& (*((char *)ptr2 + i) == 0))
			break ;
		i++;
	}
	return (0);
}
