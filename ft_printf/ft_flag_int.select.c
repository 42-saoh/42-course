/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_int_select.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:06:51 by saoh              #+#    #+#             */
/*   Updated: 2020/11/26 18:31:06 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static char		*ft_flag_precision(t_lst *lst)
{
	char		*flag_str;
	int			len;

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

static char		*ft_flag_width(t_lst *lst)
{
	char		*flag_str;
	int			len;

	len = 0;
	if (lst->width > lst->len && lst->prewidth > lst->len
			&& lst->width > lst->prewidth)
		len = lst->width - lst->prewidth;
	else if (lst->width > lst->len && lst->len >= lst->prewidth)
		len = lst->width - lst->len;
	else
		return (0);
	if (!(flag_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_error_result(lst);
		return (0);
	}
	if (lst->zero == '1' && lst->minus != '1'
			&& (lst->precision != '1' || lst->prewidth < 0))
		ft_put_symbol(flag_str, 0, len, '0');
	else
		ft_put_symbol(flag_str, 0, len, ' ');
	return (flag_str);
}

static void		ft_list_minus(t_lst *lst, char *str, char *pre, char *width)
{
		if (lst->m == 1)
			ft_lstadd_back(&lst->list, ft_lstnew(ft_strdup("-")));
		if (pre != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(pre));
		if (str != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(str));
		if (width != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(width));
}

static void		ft_list(t_lst *lst, char *str, char *pre, char *width)
{
		if (width != 0 && *width == ' ')
			ft_lstadd_back(&lst->list, ft_lstnew(width));
		if (lst->m == 1)
			ft_lstadd_back(&lst->list, ft_lstnew(ft_strdup("-")));
		if (width != 0 && *width == '0')
			ft_lstadd_back(&lst->list, ft_lstnew(width));
		if (pre != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(pre));
		if (str != 0)
			ft_lstadd_back(&lst->list, ft_lstnew(str));
}
void			ft_flag_int_select(t_lst *lst, char *str)
{
	char		*width;
	char		*pre;

	if (lst->m == 1)
		lst->width -= 1;
	pre = ft_flag_precision(lst);
	width = ft_flag_width(lst);
	if (lst->minus == '1')
		ft_list_minus(lst, str, pre, width);
	else
		ft_list(lst, str, pre, width);
}
