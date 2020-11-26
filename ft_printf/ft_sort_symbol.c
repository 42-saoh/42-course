/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:45:32 by saoh              #+#    #+#             */
/*   Updated: 2020/11/26 21:14:22 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_zero(t_lst *lst)
{
	while (*(lst->f) == '0')
		lst->f++;
	if (lst->precision != '1')
		lst->zero = '1';
	lst->nm = '1';
}

static void		ft_minus(t_lst *lst)
{
	while (*(lst->f) == '-')
		lst->f++;
	lst->minus = '1';
}

static void		ft_precision(t_lst *lst)
{
	lst->f++;
	lst->nm = '1';
	lst->precision = '1';
}

static void		ft_variable_argument_width(t_lst *lst)
{
	int			ap;

	ap = va_arg(lst->ap, int);
	if (ap < 0 && lst->precision == 0)
	{
		lst->minus = '1';
		ap = -ap;
	}
	if (lst->precision == '1' && lst->prewidth == 0)
		lst->prewidth = ap;
	else if (lst->precision == 0 && lst->width == 0)
		lst->width = ap;
	else
		return (ft_error_result(lst));
	lst->f++;
}

void			ft_sort_symbol(t_lst *lst)
{
	while (lst->result >= 0)
	{
		if (*(lst->f) >= '1' && *(lst->f) <= '9')
			ft_width(lst);
		else if (*(lst->f) == '0')
			ft_zero(lst);
		else if (*(lst->f) == '-' && lst->minus != '1' && lst->nm != '1')
			ft_minus(lst);
		else if (*(lst->f) == '*')
			ft_variable_argument_width(lst);
		else if (*(lst->f) == '.' && lst->precision != '1')
			ft_precision(lst);
		else if ((*(lst->f) >= 'a' && *(lst->f) <= 'z')
				|| (*(lst->f) >= 'A' && *(lst->f) <= 'Z') || *(lst->f) == '%')
			return (ft_format_specifier(lst));
		else
			lst->result = -1;
	}
}
