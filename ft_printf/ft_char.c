/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:17:35 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 16:51:55 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_char_minus(t_lst *lst, char *str, char c)
{
	str[0] = c;
	ft_put_symbol(str, lst->len, lst->width, ' ');
}

static void		ft_char_zero(t_lst *lst, char *str, char c)
{
	ft_put_symbol(str, 0, lst->width - lst->len, '0');
	str[lst->width - lst->len] = c;
}

static void		ft_char_precision(t_lst *lst, char *str, char c)
{
	if (lst->prewidth == lst->width)
		ft_put_symbol(str, 0, lst->width - lst->len, '0');
	else if (lst->width > lst->len)
		ft_put_symbol(str, 0, lst->width - lst->len, ' ');
	str[lst->width - lst->len] = c;
}

static void		ft_char_width(t_lst *lst, char *str, char c)
{
	ft_put_symbol(str, 0, lst->width - lst->len, ' ');
	str[lst->width - lst->len] = c;
}

void			ft_char(t_lst *lst)
{
	char	*str;
	char	va_c;

	va_c = (char)va_arg(lst->ap, int);
	lst->len = 1;
	ft_width_select(lst);
	if(!(str = (char *)malloc(sizeof(char) * (lst->width + 1))))
	{
		lst->result = -1;
		return ;
	}
	if (lst->minus == '1' && lst->width > lst->len && lst->precision != '1')
		ft_char_minus(lst, str, va_c);
	else if (lst->zero == '1' && lst->width > lst->len
			&& lst->precision != '1')
		ft_char_zero(lst, str, va_c);
	else if (lst->precision == '1' && lst->width > lst->len)
		ft_char_precision(lst, str, va_c);
	else if (lst->width > lst->len)
		ft_char_width(lst, str, va_c);
	else
		str[0] = va_c;
	str[lst->width] = 0;
	lst->f++;
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}
