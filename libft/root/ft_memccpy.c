/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:27:46 by saoh              #+#    #+#             */
/*   Updated: 2020/09/28 15:49:16 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memccpy(void *dest, void *src, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*((char *)dest + i) = *((char *)src + i);
		if (*((char *)src + i) == c)
			return (dest + (i + 1));
		i++;
	}
	return (NULL);
}
