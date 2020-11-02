/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:44:13 by saoh              #+#    #+#             */
/*   Updated: 2020/11/02 16:58:38 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *f, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, f);
	while (*f)
	{
		if (*f == '%')
			i = ft_persent();
		else
			write(1, &f, 1);
		if (i < 0)
			return (-1);
		f++;
	}
	va_end(ap);
	return (i);
}
