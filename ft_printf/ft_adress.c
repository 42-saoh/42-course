/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:05:38 by saoh              #+#    #+#             */
/*   Updated: 2020/11/11 17:35:22 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_lst				ft_adress(t_lst lst)
{
	unsigned int	adress;
	char			*str;

	if (lst.zero == '1' || lst.prewitdh > 0)
	{
		lst.result = -1;
		return (lst);
	}
	adress = va_arg(lst.ap, unsigned int);
	lst.len = 11;
	lst = ft_width_select(lst);
	if(!(str = (char *)malloc(sizeof(char) * (lst.width + 1))))
	{
		lst.result = -1;
		return (lst);
	}
	if (minus == '1')
		ft_adress_minus(lst, str, adress);
}
