/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:35:32 by saoh              #+#    #+#             */
/*   Updated: 2020/10/11 14:45:20 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*clone;
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (!(clone = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		clone[i] = str[i];
		i++;
	}
	clone[i] = 0;
	return (clone);
}