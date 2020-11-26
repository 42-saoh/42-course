/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:04:42 by saoh              #+#    #+#             */
/*   Updated: 2020/11/26 21:08:09 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		ft_int_len(t_lst *lst, int val)
{
	int			len;

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

static void		ft_negative_len(t_lst *lst, int val)
{
	long		n_val;
	int			len;

	len = 0;
	n_val = val;
	n_val = -n_val;
	while (n_val > 0)
	{
		n_val /= 10;
		len++;
	}
	lst->len = len;
	lst->m = 1;
}

static void		ft_put_str(t_lst *lst, char *str, int len, int val)
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

static void		ft_negative_put_str(char *str, int len, int val)
{
	long		n_val;

	n_val = val;
	n_val = -n_val;
	str[len--] = 0;
	while (n_val > 0)
	{
		str[len] = (n_val % 10) + '0';
		n_val /= 10;
		len--;
	}
}

void			ft_int(t_lst *lst)
{
	char		*str;
	int			val;

	str = 0;
	val = va_arg(lst->ap, int);
	if (val >= 0)
		ft_int_len(lst, val);
	else
		ft_negative_len(lst, val);
	if (lst->len != 0)
		if (!(str = (char *)malloc(sizeof(char *) * (lst->len + 1))))
			return (ft_error_result(lst));
	if (lst->m == 0)
		ft_put_str(lst, str, lst->len, val);
	else
		ft_negative_put_str(str, lst->len, val);
	lst->f++;
	ft_flag_int_select(lst, str);
}
