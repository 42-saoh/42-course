/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:50:52 by saoh              #+#    #+#             */
/*   Updated: 2020/11/10 17:51:07 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_lst	ft_width(t_lst lst)
{
	if (lst.precision == '1' && lst.prewidth == 0)
	{
		while (lst.f >= '0' && lst.f <= '9')
		{
			lst.prewidth = (lst.prewidth * 10) + (*(lst.f) - '0')
				lst.f++;
		}
	}
	else if (lst.precision == 0 && lst.width == 0)
	{
		while (lst.f >= '0' && lst.f <= '9')
		{
			lst.width = (lst.width * 10) + (*(lst.f) - '0')
				lst.f++;
		}
	}
	else
		lst.result = -1;
	return (lst);
}
