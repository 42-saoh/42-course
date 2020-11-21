/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:05:38 by saoh              #+#    #+#             */
/*   Updated: 2020/11/21 15:45:38 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static int			ft_get_len(t_lst *lst, unsigned long adress)
{
	int				len;

	len = 2;
	if (lst->precision == '1' && adress == 0)
		return (len);
	else if (adress == 0)
		return (3);
	while (adress > 0)
	{
		adress /= 16;
		len++;
	}
	return (len);
}

static void			ft_put_adress(char *str, unsigned long adress, int len)
{
	unsigned long	hex_adr;
	int				i;

	str[0] = '0';
	str[1] = 'x';
	i = len - 1;
	while (i > 1)
	{
		hex_adr = adress % 16;
		if (hex_adr >= 10)
			str[i] = hex_adr + ('a' - 10);
		else
			str[i] = hex_adr + '0';
		adress /= 16;
		i--;
	}
	str[len] = 0;
}

static void			ft_flag_select(t_lst *lst, char *str)
{
	char			*flag_str;

	if (lst->width > lst->len)
		lst->width = lst->width - lst->len;
	else
		return (ft_lstadd_back(&lst->list, ft_lstnew(str)));
	if (!(flag_str = (char *)malloc(sizeof(char) * (lst->width + 1))))
		return (ft_error_result(lst));
	ft_put_symbol(flag_str, 0, lst->width, ' ');
	if (lst->minus == 0)
	{
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
		ft_lstadd_back(&lst->list, ft_lstnew(str));
	}
	else
	{
		ft_lstadd_back(&lst->list, ft_lstnew(str));
		ft_lstadd_back(&lst->list, ft_lstnew(flag_str));
	}
}

void				ft_adress(t_lst *lst)
{
	unsigned long	adress;
	char			*str;

	if (lst->zero == '1' || lst->prewidth > 0)
		return (ft_error_result(lst));
	adress = (unsigned long)va_arg(lst->ap, void *);
	lst->len = ft_get_len(lst, adress);
	if(!(str = (char *)malloc(sizeof(char) * (lst->len + 1))))
		return (ft_error_result(lst));
	ft_put_adress(str, adress, lst->len);
	lst->f++;
	ft_flag_select(lst, str);
}
