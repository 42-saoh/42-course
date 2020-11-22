/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:53:57 by saoh              #+#    #+#             */
/*   Updated: 2020/11/22 20:22:10 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static int			ft_get_len(t_lst *lst, unsigned int val)
{
	int				len;

	len = 0;
	if (val == 0 && (lst->precision != '1' || lst->prewidth != 0))
		return (1);
	while (val > 0)
	{
		val /= 16;
		len++;
	}
	return (len);
}

static void			ft_put_hex(char *str, unsigned long val, int len)
{
	unsigned int	hex;

	str[len--] = 0;
	if (val == 0)
		str[len] = '0';
	while (val > 0)
	{
		hex = val % 16;
		if (hex >= 10)
			str[len] = hex + ('a' - 10);
		else
			str[len] = hex + '0';
		val /= 16;
		len--;
	}
}

void				ft_lower_hexadecimal(t_lst *lst)
{
	char			*str;
	unsigned int	val;

	str = 0;
	val = va_arg(lst->ap, unsigned int);
	lst->len = ft_get_len(lst, val);
	if (lst->len != 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (lst->len + 1))))
			return (ft_error_result(lst));
		ft_put_hex(str, val, lst->len);
	}
	lst->f++;
	ft_flag_unsigned_select(lst, str);
}
