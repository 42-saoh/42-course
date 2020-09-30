/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:32:53 by saoh              #+#    #+#             */
/*   Updated: 2020/09/30 19:41:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strncmp(const char *str1, const char *str2, size_t c)
{
	size_t	i;

	i = 0;
	while (i < c)
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}
