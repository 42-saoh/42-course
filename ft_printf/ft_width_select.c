/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:40:37 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 15:32:26 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void		ft_width_select(t_lst *lst)
{
	if (lst->width > lst->len && lst->width > lst->prewidth)
		lst->prewidth = 0;
	else if (lst->prewidth > lst->len && lst->prewidth >= lst->width)
		lst->width = lst->prewidth;
	else
		lst->width = lst->len;
}
