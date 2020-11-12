/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:03:40 by saoh              #+#    #+#             */
/*   Updated: 2020/11/12 18:03:57 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_numlen(long va_int)
{
	int len;

	len = 0;
	if (va_int < 0)
	{
		va_int = -va_int;
		len++;
	}
	else if (va_int == 0)
		return (1);
	while(va_int > 0)
	{
		va_int /= 10;
		len++;
	}
	return (len);
}

void		ft_put_int(char *str, long va_int, int len)
{
	while(va_int > 0)
	{
		str[len - 1] = (va_int % 10) + '0';
		va_int /= 10;
		len--;
	}
	str[len] = 0;
}

void		ft_int_minus(t_lst *lst, char *str, long va_int)
{
	if (va_int < 0)
	{
		va_int = -va_int;
		*str = '-';
		ft_put_int(str, va_int, lst->len);
	}
	else if (va_int == 0)
		*str = '0';
	else
		ft_put_int(str, va_int, lst->len);
	ft_put_symbol(str, lst->len, lst->width, ' ');
}

void		ft_int_zero(t_lst *lst, char *str, long va_int)
{
	ft_put_symbol(str, 0, lst->width - lst->len, '0');
	if (va_int < 0)
	{
		va_int = -va_int;
		str[lst->width - lst->len] = '-';
		ft_put_int(str, va_int, lst->width);
	}
	else if (va_int == 0)
	{
		str[lst->width - 1] = '0';
		str[lst->width] = 0;
	}
	else
		ft_put_int(str, va_int, lst->width);
}

void		ft_int_precision(t_lst *lst, char *str, long va_int)
{
	
}

void		ft_int_width(t_lst *lst, char *str, long va_int)
{
	ft_put_symbol(str, 0, lst->width - lst->len, ' ');
	if (va_int < 0)
	{
		va_int = -va_int;
		str[lst->width - lst->len] = '-';
		ft_put_int(str, va_int, lst->width);
	}
	else if (va_int == 0)
	{
		str[lst->width - 1] = '0';
		str[lst->width] = 0;
	}
	else
		ft_put_int(str, va_int, lst->width);
}

void		ft_int(t_lst *lst)
{
	long	va_int;
	char	*str;

	va_int = (long)va_arg(lst->ap, int);
	lst->len = ft_numlen(va_int);
	ft_width_select(lst);
	if (!(str = (char *)malloc(sizeof(char) * (lst->width + 1))))
	{
		lst->result = -1;
		return ();
	}
	if (lst->minus == '1' && lst->width > lst->len && lst->precision != '1')
		ft_int_minus(lst, str, va_int);
	else if (lst->zero == '1' && lst->width > lst->len
			&& lst->precision != '1')
		ft_int_zero(lst, str, va_int);
	else if (lst->precision == '1' && lst->width > lst->len)
		ft_int_precision(lst, str, va_int);
	else if (lst->width > lst->len)
		ft_int_width(lst, str, va_int);
	else
		str = va_str;
	ft_lstadd_back(&lst->list, ft_lstnew(str));
}
