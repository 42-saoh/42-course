/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:44:13 by saoh              #+#    #+#             */
/*   Updated: 2020/11/10 17:59:07 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static t_lst		ft_init_lst(t_lst lst)
{
	lst.minus = 0;
	lst.result = 0;
	lst.zero = 0;
	lst.minus = 0;
	lst.nm = 0;
	lst.precision = 0;
	lst.width = 0;
	lst.prewidth = 0;
	lst.len = 0;
	return (lst);
}

static t_lst		ft_until_persent_str(lst);
{
	char			*str;

	if (lst.chrf == lst.f)
	{
		lst.f++;
		return (lst);
	}
	if (!(str = ft_substr(lst.f, 0, lst.chrf - lst.f)))
	{
		lst.result = -1;
		return (lst);
	}
	ft_lstadd_back(&lst.list, ft_lstnew(str));
	lst.f = lst.chrf + 1;
	return (lst);
}

int			ft_printf(const char *f, ...)
{
	t_lst	lst;
	
	lst.f = f;
	lst.list = NULL;
	va_start(lst.ap, lst.f);
	while (lst.chrf = ft_strchr(lst.f, '%'))
	{
		lst = ft_init_lst(lst);
		lst = ft_until_persent_str(lst);
		lst = ft_sort_symbol(lst);
		if (lst.result < 0)
			return (ft_error);
	}
	lst = ft_print(lst);
	ft_free(lst);
	va_end(lst.ap);
	return (lst.result);
}
