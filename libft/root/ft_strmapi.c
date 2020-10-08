/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:19:24 by saoh              #+#    #+#             */
/*   Updated: 2020/10/08 14:58:23 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ch_str;

	i = 0;
	while (s[i])
		i++;
	if (!(ch_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ch_str[i] = f(i, s[i]);
		i++;
	}
	return (ch_str);
}
