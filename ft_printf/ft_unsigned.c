/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:15:35 by saoh              #+#    #+#             */
/*   Updated: 2020/11/21 17:22:11 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void			ft_int_len(t_lst *lst, unsigned int val)
{
	int				len;

	if (val == 0 && lst->precision == '1')
	{
		lst->len = 0;
		return ;
	}
	else if (val == 0)
	{
		lst->len = 1;
		return ;
	}
	len = 0;
	while (val > 0)
	{
		val /= 10;
		len++;
	}
	lst->len = len;
}

static void			ft_put_str(t_lst *lst, char *str, int len, unsigned int val)
{
	if (val == 0 && lst->precision == '1')
	{
		return ;
	}
	else if (val == 0)
	{
		str[0] = '0';
		str[1] = 0;
		return ;
	}
	str[len--] = 0;
	while (val > 0)
	{
		str[len] = (val % 10) + '0';
		val /= 10;
		len--;
	}
}

char				*ft_flag_precision(t_lst *lst)
{
	char			*flag_str;
	int				len;

	len = 0;
	if (lst->prewidth > lst->len)
		len = lst->prewidth - lst->len;
	else
		return (0);
	if (!(flag_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_error_result(lst);
		return (0);
	}
	ft_put_symbol(flag_str, 0, len, '0');
	return (flag_str);
}

char				*ft_flag_width(t_lst *lst)
{
	char			*flag_str;
	int				len;

	len = 0;
	if (lst->width > lst->len && lst->prewidth > lst->len
			&& lst->width > lst->prewidth)
		len = lst->width - lst->prewidth;
	else if (lst->width > lst->len && lst->len > lst->prewidth)
		len = lst->width - lst->len;
	else
		return (0);
	if (!(flag_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_error_result(lst);
		return (0);
	}
	if (lst->zero == '1')
		ft_put_symbol(flag_str, 0, len, '0');
	else
		ft_put_symbol(flag_str, 0, len, ' ');
	return (flag_str);
}

static void			ft_flag_select(t_lst *lst, char *str)
{
	char			*flag_width;
	char			*flag_pre;

	flag_pre = ft_flag_precision(lst);
	flag_width = ft_flag_width(lst);
	if (lst->minus == '1')
	{
		if (flag_pre != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(flag_pre));
		if (str != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(str));
		if (flag_width != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(flag_width));
	}
	else
	{
		if (flag_width != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(flag_width));
		if (flag_pre != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(flag_pre));
		if (str != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(str));
	}
}

void				ft_unsigned(t_lst *lst)
{
	char			*str;
	unsigned int	val;

	str = 0;
	val = va_arg(lst->ap, unsigned int);
	ft_int_len(lst, val);
	if (lst->len != 0)
		if (!(str = (char *)malloc(sizeof(char *) * (lst->len + 1))))
			return (ft_error_result(lst));
	ft_put_str(lst, str, lst->len, val);
	lst->f++;
	ft_flag_select(lst, str);
}
