/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:50:52 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 15:30:33 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_width(t_lst *lst)
{
	if (lst->precision == '1' && lst->prewidth == 0)
	{
		while (*(lst->f) >= '0' && *(lst->f) <= '9')
		{
			lst->prewidth = (lst->prewidth * 10) + (*(lst->f) - '0');
			lst->f++;
		}
	}
	else if (lst->precision == 0 && lst->width == 0)
	{
		while (*(lst->f) >= '0' && *(lst->f) <= '9')
		{
			lst->width = (lst->width * 10) + (*(lst->f) - '0');
			lst->f++;
		}
	}
	else
		lst->result = -1;
}
