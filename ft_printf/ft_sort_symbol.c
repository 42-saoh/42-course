/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:45:32 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 15:34:27 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_zero(t_lst *lst)
{
	while(*(lst->f) == '0')
		lst->f++;
	if (lst->precision != '1')
		lst->zero = '1';
	lst->nm = '1';
}

static void		ft_minus(t_lst *lst)
{
	lst->f++;
	lst->minus = '1';
}

static void		ft_precision(t_lst *lst)
{
	lst->f++;
	lst->nm = '1';
	lst->precision = '1';
}

static void		ft_persent(t_lst *lst)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
	{
		lst->result = -1;
		return ;
	}
	lst->f++;
	str[0] = '%';
	str[1] = 0;
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}

void		ft_sort_symbol(t_lst *lst)
{
	while (lst->result >= 0)
	{
		if (*(lst->f) >= '1' && *(lst->f) <= '9')
			ft_width(lst);
		else if (*(lst->f) == '0' && lst->minus != '1')
			ft_zero(lst);
		else if (*(lst->f) == '-' && lst->minus != '1' && lst->nm != '1')
			ft_minus(lst);
		else if (*(lst->f) == '*')
			ft_variable_argument_width(lst);
		else if (*(lst->f) == '.' && lst->precision != '1')
			ft_precision(lst);
		else if (*(lst->f) == '%' && *(lst->f - 1) == '%')
			return (ft_persent(lst));
		else if ((*(lst->f) >= 'a' && *(lst->f) <= 'z')
				|| (*(lst->f) >= 'A' && *(lst->f) <= 'Z'))
			return (ft_format_specifier(lst));
		else
			lst->result = -1;
	}
}
