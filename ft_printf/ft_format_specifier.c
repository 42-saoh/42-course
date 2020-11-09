/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:52:25 by saoh              #+#    #+#             */
/*   Updated: 2020/11/09 21:01:10 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_lst	ft_format_specifier(t_lst lst)
{
	if (*(lst.f) == 'c')
		return (ft_char(lst));
	else if (*(lst.f) == 's')
		return (ft_str(lst));
	else if (*(lst.f) == 'p')
		return (ft_adress(lst));
	else if (*(lst.f) == 'd' || *(lst.f + 1) == 'i')
		return (ft_int(lst));
	else if (*(lst.f) == 'u')
		return (ft_unsigned_int(lst));
	else if (*(lst.f) == 'x')
		return (ft_lower_hexadecimal(lst));
	else if (*(lst.f) == 'X')
		return (ft_upper_hexadecimal(lst));
	else
	{
		lst.result = -1;
		return (lst);
	}
}
