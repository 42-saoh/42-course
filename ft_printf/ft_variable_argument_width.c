/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variable_argument_width.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:51 by saoh              #+#    #+#             */
/*   Updated: 2020/11/16 20:18:53 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_variable_argument_width(t_lst *lst)
{
	int	ap;

	ap = va_arg(lst->ap, int);
	if (ap < 0 && lst->precision == 0)
	{
		lst->minus = '1';
		ap = -ap;
	}
	if (lst->precision == '1' && lst->prewidth == 0)
		lst->prewidth = ap;
	else if (lst->precision == 0 && lst->width == 0)
		lst->width = ap;
	else
	{
		lst->result = -1;
		return ;
	}
	lst->f++;
}
