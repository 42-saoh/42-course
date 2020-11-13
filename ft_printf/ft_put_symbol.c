/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:37:01 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 15:23:03 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_put_symbol(char *str, int start, int end, char c)
{
	while(start < end)
	{
		str[start] = c;
		start++;
	}
	str[start] = 0;
}
