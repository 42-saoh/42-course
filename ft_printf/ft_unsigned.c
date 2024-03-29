/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:15:35 by saoh              #+#    #+#             */
/*   Updated: 2020/11/22 17:47:20 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void			ft_int_len(t_lst *lst, unsigned int val)
{
	int				len;

	if (val == 0 && lst->precision == '1' && lst->prewidth == 0)
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
	if (val == 0 && lst->precision == '1' && lst->prewidth == 0)
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
	ft_flag_unsigned_select(lst, str);
}
