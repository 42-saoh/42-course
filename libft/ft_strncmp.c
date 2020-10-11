/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:32:53 by saoh              #+#    #+#             */
/*   Updated: 2020/10/11 14:19:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *str1, const char *str2, size_t c)
{
	size_t			i;

	i = 0;
	while (i < c && (str1[i] || str2[i]))
	{
		if ((unsigned char)str1[i] > (unsigned char)str2[i]
				|| (str1[i] != 0 && str2[i] == 0))
			return (1);
		else if ((unsigned char)str1[i] < (unsigned char)str2[i]
				|| (str1[i] == 0 && str2[i] != 0))
			return (-1);
		i++;
	}
	return (0);
}
