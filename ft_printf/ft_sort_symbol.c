/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:45:32 by saoh              #+#    #+#             */
/*   Updated: 2020/11/10 17:48:30 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_lst		ft_zero(t_lst lst)
{
	while(*(lst.f) == '0')
		lst.f++;
	if (lst.precision != '1')
		lst.zero = '1';
	lst.nm = '1';
	return (lst);
}

static t_lst		ft_minus(t_lst lst)
{
	lst.f++;
	lst.minus = '1';
	return (lst);
}

static t_lst		ft_precision(t_lst lst)
{
	lst.f++;
	lst.zero = 0;
	lst.minus = 0;
	lst.nm = '1';
	lst.precision = '1';
	return (lst);
}

static t_lst		ft_persent(t_lst lst)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
	{
		lst.result = -1;
		return (lst);
	}
	lst.f++;
	str[0] = '%';
	str[1] = 0;
	ft_lstadd_back(&lst.list, ft_lstnew(str));
	return (lst);
}

t_lst		ft_sort_symbol(t_lst lst)
{
	while (lst.result >= 0)
	{
		if (*(lst.f) >= '1' && *(lst.f) <= '9')
			lst = ft_width(lst);
		else if (*(lst.f) == '0' && lst.minus != '1')
			lst = ft_zero(lst);
		else if (*(lst.f) == '-' && lst.minus != '1' && lst.nm != '1')
			lst = ft_minus(lst);
		else if (*(lst.f) == '*')
			lst = ft_variable_argument_width(lst);
		else if (*(lst.f) == '.' && lst.precision != '1')
			lst = ft_precision(lst);
		else if (*(lst.f) == '%' && *(lst.f - 1) == '%')
			return (ft_persent(lst));
		else if ((*(lst.f) >= 'a' && *(lst.f) <= 'z')
				|| (*(lst.f) >= 'A' && *(lst.f) <= 'Z'))
			return (ft_format_specifier(lst));
		else
			lst.result = -1;
	}
	return (lst);
}
