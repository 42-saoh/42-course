/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:21:59 by saoh              #+#    #+#             */
/*   Updated: 2020/09/28 19:29:17 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *ptr, int val, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (*((char *)ptr + i) == val)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
