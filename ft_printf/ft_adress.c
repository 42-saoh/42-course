/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:05:38 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 15:40:14 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void			ft_put_adress(char *str, unsigned int adress)
{
	int				i;
	unsigned int	hex_adr;

	str[0] = '0';
	str[1] = 'x';
	str[2] = '1';
	i = 10;
	while (i > 2)
	{
		hex_adr = adress % 16;
		if (hex_adr > 10)
			str[i] = hex_adr + ('a' - 10);
		else
			str[i] = hex_adr + '0';
		adress /= 16;
		i--;
	}
	str[11] = 0;
}

static void			ft_adress_minus(t_lst *lst, char *str, unsigned int adress)
{
	ft_put_adress(str, adress);
	ft_put_symbol(str, 11, lst->width, ' ');
}

static void			ft_adress_width(t_lst *lst, char *str, unsigned int adress)
{
	ft_put_symbol(str, 0, lst->width - lst->len, ' ');
	ft_put_adress(str + (lst->width - lst->len),  adress);
}

void				ft_adress(t_lst *lst)
{
	unsigned int	adress;
	char			*str;

	if (lst->zero == '1' || lst->prewidth > 0)
	{
		lst->result = -1;
		return ;
	}
	adress = (unsigned int)va_arg(lst->ap, void *);
	lst->len = 11;
	ft_width_select(lst);
	if(!(str = (char *)malloc(sizeof(char) * (lst->width + 1))))
	{
		lst->result = -1;
		return ;
	}
	if (lst->minus == '1')
		ft_adress_minus(lst, str, adress);
	else if (lst->width > lst->len)
		ft_adress_width(lst, str, adress);
	else
		ft_put_adress(str, adress);
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}
