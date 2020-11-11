/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:17:35 by saoh              #+#    #+#             */
/*   Updated: 2020/11/11 17:58:29 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_char_minus(t_lst lst, char *str, char c)
{
	str[0] = c;
	ft_put_symbol(str, lst.len, lst.width, ' ');
}

static void		ft_char_zero(t_lst lst, char *str, char c)
{
	ft_put_symbol(str, 0, lst.width - lst.len, '0');
	str[lst.width - lst.len] = c;
}

static void		ft_char_precision(t_lst lst, char *str, char c)
{
	if (lst.prewidth == lst.width)
		ft_put_symbol(str, 0, lst.width - lst.len, '0');
	else if (lst.width > lst.len)
		ft_put_symbol(str, 0, lst.width - lst.len, ' ');
	str[lst.width - lst.len] = c;
}

static void		ft_char_width(t_lst lst, char *str, char c)
{
	ft_put_symbol(str, 0, lst.width - lst.len, ' ');
	str[lst.width - lst.len] = c;
}

t_lst			ft_char(t_lst lst)
{
	char	va_c;
	char	*str;

	va_c = va_arg(lst.ap, char);
	lst.len = 1;
	lst = ft_width_select(lst);
	if(!(str = (char *)malloc(sizeof(char) * (lst.width + 1))))
	{
		lst.result = -1;
		return (lst);
	}
	if (lst.minus == '1' && lst.width > lst.len && lst.precision != '1')
		ft_char_minus(lst, str, va_c);
	else if (lst.zero == '1' && lst.width > lst.len && lst.precision != '1')
		ft_char_zero(lst, str, va_c);
	else if (lst.precision == '1' && lst.width > lst.len)
		ft_char_precision(lst, str, va_c);
	else if (lst.width > lst.len)
		ft_char_width(lst, str, va_c);
	else
		str[0] = va_c;
	str[lst.width] = 0;
	lst.f++;
	ft_lstadd_back(%lst.list, ft_lstnew(str));
	return (lst);
}
