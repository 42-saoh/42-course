/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:37:17 by saoh              #+#    #+#             */
/*   Updated: 2020/11/21 15:58:19 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_flag_select(t_lst *lst, char *str)
{
	char		*flag_str;

	if (lst->width > lst->len)
		lst->width -= lst->len;
	else
		return (ft_lstadd_back(&lst->list, ft_lstnew(str)));
	if (!(flag_str = (char *)malloc(sizeof(char) * (lst->width + 1))))
		return (ft_error_result(lst));
	if (lst->zero == '1' && lst->minus !='1')
		ft_put_symbol(flag_str, 0, lst->width, '0');
	else
		ft_put_symbol(flag_str, 0, lst->width, ' ');
	if (lst->minus == '1')
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

void		ft_persent(t_lst *lst)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (ft_error_result(lst));
	lst->len = 1;
	str[0] = '%';
	str[1] = 0;
	lst->f++;
	ft_flag_select(lst, str);
}
