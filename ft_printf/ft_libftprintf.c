/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:44:13 by saoh              #+#    #+#             */
/*   Updated: 2020/11/09 21:03:45 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

t_lst		ft_zero(t_lst lst)
{
	while(*(lst.f) == '0')
		lst.f++;
	if (lst.precision != '1')
		lst.zero = '1';
	lst.nm = '1';
	return (lst);
}

t_lst		ft_minus(t_lst lst)
{
	lst.f += 1;
	lst.minus = '1';
	return (lst);
}

t_lst		ft_precision(t_lst lst)
{
	lst.f += 1;
	lst.zero = 0;
	lst.minus = 0;
	lst.nm = '1';
	lst.precision = '1';
	return (lst);
}

t_lst		ft_width(t_lst lst)
{
	if (lst.precision == '1' && lst.prewidth == 0)
	{
		while (lst.f >= '0' && lst.f <= '9')
		{
			lst.prewidth = (lst.prewidth * 10) + (*(lst.f) - '0')
			lst.f++;
		}
	}
	else if (lst.precision == 0 && lst.width == 0)
	{
		while (lst.f >= '0' && lst.f <= '9')
		{	
			lst.width = (lst.width * 10) + (*(lst.f) - '0')
			lst.f++;
		}
	}
	else
		lst.result = -1;
	return (lst);
}

t_lst		ft_variable_argument_width(t_lst lst)
{
	if (lst.precision == '1' && lst.prewidth == 0)
		lst.prewidth = va_arg(lst.ap, int);
	else if (lst.precision == 0 && lst.width == 0)
		lst.width = va_arg(lst.ap, int);
	else
		lst.result = -1;
	return (lst);
}

t_lst		ft_sort_symbol(t_lst lst)
{
	while (lst.result >= 0)
	{
		if (*(lst.f) >= '1' && *(lst.f) <= '9')
			lst = ft_width(lst);
		else if (*(lst.f) == '0' && lst.minus != '1')
			lst = ft_zero(lst);
		else if (*(lst.f) == '-' && lst.minus != '1' && lst.nm != '1')
			lst = ft_minus(lst);
		else if (*(lst.f) == '*')
			lst = ft_variable_argument_width(lst);
		else if (*(lst.f) == '.' && lst.precision != '1')
			lst = ft_precision(lst);
		else if (*(lst.f) == '%' && *(lst.f - 1) == '%')
			lst = ft_persent(lst);
		else if ((*(lst.f) >= 'a' && *(lst.f) <= 'z')
				|| (*(lst.f) >= 'A' && *(lst.f) <= 'Z'))
			return (ft_format_specifier(lst));
		else
		{
			lst.result = -1;
		}
	}
	return (lst);
}

int			ft_printf(const char *f, ...)
{
	t_lst	lst;
	
	lst.f = f;
	va_start(lst.ap, lst.f);
	while (lst.chrf = ft_strchr(lst.f, '%'))
	{
		lst = ft_init_lst(lst);
		lst = ft_putstr(lst);
		lst = ft_sort_symbol(lst);
		if (lst.result < 0)
			return (ft_error);
	}
	lst = ft_print(lst);
	ft_free(lst);
	va_end(lst.ap);
	return (lst.result);
}
