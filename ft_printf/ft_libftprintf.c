/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:44:13 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 16:20:21 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_init_lst(t_lst *lst)
{
	lst->minus = 0;
	lst->result = 0;
	lst->zero = 0;
	lst->nm = 0;
	lst->precision = 0;
	lst->width = 0;
	lst->prewidth = 0;
	lst->len = 0;
}

static void		ft_until_persent_str(t_lst *lst)
{
	char			*str;

	if (lst->chrf == lst->f)
	{
		lst->f++;
		return ;
	}
	if (!(str = ft_substr(lst->f, 0, lst->chrf - lst->f)))
	{
		lst->result = -1;
		return ;
	}
	ft_lstadd_back(&lst->list, ft_lstnew(str));
	lst->f = lst->chrf + 1;
}

void		ft_print(t_lst *lst)
{
	t_list 	*curr;
	int		len;

	curr = lst->list;
	len = 0;
	while(curr != NULL)
	{
		len = ft_strilen(curr->content);
		write(1, curr->content, len);
		lst->result = lst->result + len;
		curr = curr->next;
	}
}

int			ft_printf(const char *f, ...)
{
	t_lst	*lst;
	
	if (!(lst = malloc(sizeof(t_lst))))
		return (-1);
	lst->list = NULL;
	lst->f = (char *)f;
	va_start(lst->ap, f);
	while (lst->chrf == ft_strchr(lst->f, '%'))
	{
		ft_init_lst(lst);
		ft_until_persent_str(lst);
		ft_sort_symbol(lst);
		if (lst->result < 0)
			return (-1);
	}
	ft_print(lst);
	va_end(lst->ap);
	return (lst->result);
}
