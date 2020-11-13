/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variable_argument_width.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:51 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 15:30:59 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_variable_argument_width(t_lst *lst)
{
	if (lst->precision == '1' && lst->prewidth == 0)
		lst->prewidth = va_arg(lst->ap, int);
	else if (lst->precision == 0 && lst->width == 0)
		lst->width = va_arg(lst->ap, int);
	else
	{
		lst->result = -1;
		return ;
	}
	lst->f++;
}
