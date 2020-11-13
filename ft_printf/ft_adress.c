/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:05:38 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 18:09:51 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int					ft_get_len(unsigned long adress)
{
	int				len;

	len = 2;
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

static void			ft_adress_minus(t_lst *lst, char *str, unsigned long adress)
{
	ft_put_adress(str, adress, lst->len);
	ft_put_symbol(str, 11, lst->width, ' ');
}

static void			ft_adress_width(t_lst *lst, char *str, unsigned long adress)
{
	ft_put_symbol(str, 0, lst->width - lst->len, ' ');
	ft_put_adress(str + (lst->width - lst->len),  adress, lst->len);
}

void				ft_adress(t_lst *lst)
{
	unsigned long	adress;
	char			*str;

	if (lst->zero == '1' || lst->prewidth > 0)
	{
		lst->result = -1;
		return ;
	}
	adress = (unsigned long)va_arg(lst->ap, void *);
	lst->len = ft_get_len(adress);
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
		ft_put_adress(str, adress, lst->len);
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}
