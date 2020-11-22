/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:52:25 by saoh              #+#    #+#             */
/*   Updated: 2020/11/22 20:23:10 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_format_specifier(t_lst *lst)
{
	if (*(lst->f) == 'c')
		return (ft_char(lst));
	else if (*(lst->f) == 's')
		return (ft_str(lst));
	else if (*(lst->f) == 'p')
		return (ft_adress(lst));
	else if (*(lst->f) == '%')
		return (ft_persent(lst));
	else if (*(lst->f) == 'u')
		return (ft_unsigned(lst));
	else if (*(lst->f) == 'i' || *(lst->f) == 'd')
		return (ft_int(lst));
	else if (*(lst->f) == 'x')
		return (ft_lower_hexadecimal(lst));
	else if (*(lst->f) == 'X')
		return (ft_upper_hexadecimal(lst));
	else
		return (ft_error_result(lst));
}
