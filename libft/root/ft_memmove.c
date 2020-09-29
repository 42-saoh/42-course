/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:31:23 by saoh              #+#    #+#             */
/*   Updated: 2020/09/28 16:57:58 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memmove(void *dest, void *src, size_t size)
{
	size_t	i;
	char	clone[size];

	i = 0;
	while (i < size)
	{
		clone[i] = *((char *)src + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		*((char *)dest + i) = clone[i];
		i++;
	}
}
