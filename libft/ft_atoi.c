/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:07:11 by saoh              #+#    #+#             */
/*   Updated: 2020/10/11 14:36:52 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	long	minus;
	long	val;

	minus = 1;
	i = 0;
	val = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i] != 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != 0)
	{
		val = (val * 10) + (str[i] - '0');
		if (val * minus > 2147483647)
			return (-1);
		else if (val * minus < -2147483648)
			return (0);
		i++;
	}
	return (val * minus);
}
