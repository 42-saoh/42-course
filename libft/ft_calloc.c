/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:38:50 by saoh              #+#    #+#             */
/*   Updated: 2020/10/08 14:17:41 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t elt_count, size_t elt_size)
{
	size_t	i;
	void	*temp;

	if (!(temp = (void *)malloc(elt_size * elt_count)))
		return (NULL);
	i = 0;
	while (i < elt_count * elt_size)
	{
		*((char *)temp + i) = 0;
		i++;
	}
	return (temp);
}
