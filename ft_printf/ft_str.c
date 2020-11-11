/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:47 by saoh              #+#    #+#             */
/*   Updated: 2020/11/11 17:13:13 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_str_minus(t_lst lst, char *str, char *va_str)
{
	ft_strlcpy(str, va_str, lst.len + 1);
	ft_put_symbol(str, lst.len, lst.width, ' ');
}

static void		ft_str_zero(t_lst lst, char *str, char *va_str)
{
	ft_put_symbol(str, 0, lst.width - lst.len, '0');
	ft_strlcat(str, va_str, lst.width + 1);
}

static void		ft_str_precision(t_lst lst, char *str, char *va_str)
{
	if (lst.prewidth == lst.width)
		ft_put_symbol(str, 0, lst.width - lst.len, '0');
	else if (lst.width > lst.len)
		ft_put_symbol(str, 0, lst.width - lst.len, ' ');
	ft_strlcat(str, va_str, lst.width + 1);
}

t_lst			ft_str(t_lst lst)
{
	char	*va_str;
	char	*str

	va_str = va_arg(lst.ap, char *);
	lst.len = ft_strilen(va_str);
	lst = ft_width_select(lst);
	if(!(str = (char *)malloc(sizeof(char) * (lst.width + 1))))
	{
		lst.result = -1;
		return (lst);
	}
	if (lst.minus == '1' && lst.width > len && lst.precision != '1')
		ft_str_minus(lst, str, va_str);
	else if (lst.zero == '1' && lst.width > len && lst.precision != '1')
		ft_str_zero(lst, str, va_str);
	else if (lst.precision == '1' && lst.width > len)
		ft_str_precision(lst, str, va_str);
	else
		str = va_str;
	ft_lstadd_back(%lst.list, ft_lstnew(str));
	return (lst);
}
