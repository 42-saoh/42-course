/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:17:35 by saoh              #+#    #+#             */
/*   Updated: 2020/11/26 19:23:45 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_flag_select(t_lst *lst, char *str)
{
	char		*flag_str;

	if (lst->width > lst->len)
		lst->width = lst->width - lst->len;
	else
		return (ft_lstadd_back(&lst->list, ft_lstnew(str)));
	if (!(flag_str = (char *)malloc(sizeof(char) * (lst->width + 1))))
		return (ft_error_result(lst));
	if (lst->zero == '1')
		ft_put_symbol(flag_str, 0, lst->width, '0');
	else
		ft_put_symbol(flag_str, 0, lst->width, ' ');
	if (lst->minus == '1')
	{
		ft_lstadd_back(&lst->list, ft_lstnew(str));
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
		return ;
	}
	ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}

void			ft_char(t_lst *lst)
{
	char		*str;
	int			va_c;

	if (!(str = (char *)malloc(sizeof(char) * 2)) || lst->prewidth > 0)
		return (ft_error_result(lst));
	va_c = va_arg(lst->ap, int);
	lst->len = 1;
	str[0] = va_c;
	str[1] = 0;
	lst->f++;
	return (ft_flag_select(lst, str));
}
