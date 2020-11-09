/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:47 by saoh              #+#    #+#             */
/*   Updated: 2020/11/09 21:04:58 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_lst		ft_str(t_lst lst)
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
	if (lst.minus == '1' && lst.width > len)
		ft_char_minus(lst, str, va_str);
	else if (lst.zero == '1' && lst.width > len)
		ft_char_zero(lst, str, va_str);
	else if (lst.precision == '1' && lst.width > len)
		ft_char_precision(lst, str, va_str);
	else
		str = ft_strdup(va_str);
	ft_lstadd_back(%lst.list, ft_lstnew(str));
	return (lst);
}
