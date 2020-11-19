/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:47 by saoh              #+#    #+#             */
/*   Updated: 2020/11/19 16:35:26 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_str_minus(t_lst *lst, char *str, char *va_str)
{
	ft_put_symbol(str, lst->len, lst->width, ' ');
}

static void		ft_str_zero(t_lst *lst, char *str, char *va_str)
{
	ft_put_symbol(str, 0, lst->width - lst->len, '0');
}

static void		ft_str_precision(t_lst *lst, char *str, char *va_str)
{
	if (lst->prewidth == lst->width)
		ft_put_symbol(str, 0, lst->width - lst->len, '0');
	else if (lst->width > lst->len)
		ft_put_symbol(str, 0, lst->width - lst->len, ' ');
	ft_strlcat(str, va_str, lst->width + 1);
}

static void		ft_str_width(t_lst *lst, char *str, char *va_str)
{
	ft_put_symbol(str, 0, lst->width - lst->len, ' ');
}

static void		ft_flag_select(t_lst lst, char *str)
{
	char		*flag_str;

	
	if(!(flag_str = (char *)malloc(sizeof(char) * (lst->width + 1))))
		return (ft_error_result(lst));
	if (lst->minus == '1' && lst->width > lst->len && lst->precision != '1')
		ft_str_minus(lst, str, va_str);
	else if (lst->zero == '1' && lst->width > lst->len
			&& lst->precision != '1')
		ft_str_zero(lst, str, va_str);
	else if (lst->precision == '1' && lst->width > lst->len)
		ft_str_precision(lst, str, va_str);
	else if (lst->width > lst->len)
		ft_str_width(lst, str, va_str);
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}

void			ft_str(t_lst *lst)
{
	char		*va_str;
	char		*str;

	va_str = va_arg(lst->ap, char *);
	if (!(str = ft_strdup(va_str)))
		return (ft_error_result(lst)):
	lst->len = ft_strilen(va_str);
	lst->f++;
	ft_flag_select(lst, str);
}
