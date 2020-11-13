/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:52:25 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 16:45:42 by saoh             ###   ########.fr       */
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
	else
	{
		lst->result = -1;
		return ;
	}
}
