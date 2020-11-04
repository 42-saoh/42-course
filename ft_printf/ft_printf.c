/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:44:13 by saoh              #+#    #+#             */
/*   Updated: 2020/11/04 14:12:48 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst		ft_persent(t_lst lst)
{
	if (*(lst.f + 1) == NULL)
	{
		lst.result = -1;
		return (lst);
	}
	if (*(lst.f + 1) == 
}

int			ft_printf(const char *f, ...)
{
	t_lst	lst;
	
	lst.f = f;
	va_start(lst.ap, lst.f);
	while (*lst.f)
	{
		if (ft_strchr(*lst.f, '%') != NULL)
			lst = ft_persent(lst);
		if (lst.result < 0)
			return (-1);
	}
	va_end(lst.ap);
	return (lst.result);
}
