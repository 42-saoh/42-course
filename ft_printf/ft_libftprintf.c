/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:44:13 by saoh              #+#    #+#             */
/*   Updated: 2020/11/08 20:44:20 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

t_lst		ft_format_specifier(t_lst lst)
{
	if (*(lst.f + 1) == 'c')
		return (ft_char(lst));
	else if (*(lst.f + 1) == 's')
		return (ft_str(lst));
	else if (*(lst.f + 1) == 'p')
		return (ft_adress(lst));
	else if (*(lst.f + 1) == 'd' || *(lst.f + 1) == 'i')
		return (ft_int(lst));
	else if (*(lst.f + 1) == 'u')
		return (ft_unsigned_int(lst));
	else if (*(lst.f + 1) == 'x')
		return (ft_lower_hexadecimal(lst));
	else if (*(lst.f + 1) == 'X')
		return (ft_upper_hexadecimal(lst));
	else
	{
		lst.result = -1;
		return (lst);
	}
}

void		ft_zero(t_lst lst)
{
	while(*(lst.f) == '0')
		lst.f++;
	lst.zero = '1';
	lst.nm = '1';
	ft_sort_symbol(lst);
}

void		ft_minus(t_lst lst)
{
	lst.f += 1;
	lst.minus = '1';
	ft_sort_symbol(lst);
}

void		ft_precision(t_lst lst)
{
	lst.f += 1;
	lst.minus = 0;
	lst.nm = '1';
	lst.precision = '1';
	lst.zero = 0;
	ft_sort_symbol(lst);
}

t_lst		ft_sort_symbol(t_lst lst)
{
	if (*(lst.f) >= '1' && *(lst.f) <= '9')
		ft_number(lst);
	else if (*(lst.f) == '0' && lst.minus != '1')
		ft_zero(lst);
	else if (*(lst.f) == '-' && lst.minus != '1' && lst.nm != '1')
		ft_minus(lst);
	else if (*(lst.f) == '*')
		ft_star(lst);
	else if (*(lst.f) == '.')
		ft_precision(lst);
	else if (*(lst.f) == '%' && *(lst.f - 1) == '%')
		ft_persent(lst);
	else if ((*(lst.f) >= 'a' && *(lst.f) <= 'z')
			|| (*(lst.f) >= 'A' && *(lst.f) <= 'Z'))
		return (ft_f1111ormat_specifier(lst));
	else
	{
		lst.result = -1;
		return (lst);
	}
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
