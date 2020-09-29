/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:57:46 by saoh              #+#    #+#             */
/*   Updated: 2020/09/29 13:58:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + 32;
	return (ch);
}
