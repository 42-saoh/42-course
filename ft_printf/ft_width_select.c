/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:40:37 by saoh              #+#    #+#             */
/*   Updated: 2020/11/09 21:04:41 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_lst		ft_width_select(t_lst lst)
{
	if (lst.width > lst.len && lst.width > lst.prewidth)
		lst.prewidth = 0;
	else if (lst.prewidth > lst.len && lst.prewidth >= lst.width)
		lst.width = lst.prewidth;
	else
		lst.width = len;
	return (lst);
}
