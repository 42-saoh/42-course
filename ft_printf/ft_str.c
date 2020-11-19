/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:47 by saoh              #+#    #+#             */
/*   Updated: 2020/11/19 21:04:57 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_put_list(t_lst *lst, char *str, char *flag_str)
{
	if (str == 0)
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
	else if (*str == 0 && flag_str != 0)
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
	else if (*str == 0 && flag_str == 0)
		return ;
	else if (*str != 0 && flag_str == 0)
		ft_lstadd_back(&lst->list, ft_lstnew(str));
	else if (lst->minus == '1')
	{
		ft_lstadd_back(&lst->list, ft_lstnew(str));
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
	}
	else
	{
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
		ft_lstadd_back(&lst->list, ft_lstnew(str));
	}
}

static char		*ft_symbol_select(t_lst *lst)
{
	char *flag_str;

	if (lst->width == 0)
		return (0);
	if (!(flag_str = (char *)malloc(sizeof(char) * (lst->width + 1))))
	{
		ft_error_result(lst);
		return (0);
	}
	if (lst->zero == '1')
		ft_put_symbol(flag_str, 0, lst->width, '0');
	else
		ft_put_symbol(flag_str, 0, lst->width, ' ');
	return (flag_str);
}

static void		ft_flag_select(t_lst *lst)
{
	if (lst->precision == 0)
	{
		if (lst->len >= lst->width)
			lst->width = 0;
		else
			lst->width = lst->width - lst->len;
	}
	else
	{
		if (lst->prewidth >= 0 && lst->len > lst->prewidth)
			lst->len = lst->prewidth;
		if (lst->width > lst->len)
			lst->width = lst->width - lst->len;
		else
			lst->width = 0;
	}
}

void			ft_str(t_lst *lst)
{
	char		*va_str;
	char		*flag_str;
	char		*str;

	va_str = va_arg(lst->ap, char *);
	if (va_str != 0)
	{
		lst->len = ft_strilen(va_str);
		ft_flag_select(lst);
		if (!(str = ft_substr(va_str, 0, lst->len)))
			return (ft_error_result(lst));
	}
	else
	{
		lst->len = 6;
		ft_flag_select(lst);
		if (!(str = ft_substr("(null)", 0, lst->len)))
			return (ft_error_result(lst));
	}
	lst->f++;
	flag_str = ft_symbol_select(lst);
	ft_put_list(lst, str, flag_str);
}
