/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:18:36 by saoh              #+#    #+#             */
/*   Updated: 2020/10/08 14:59:05 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(char const *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_del_num(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		del_num;

	i = 0;
	del_num = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				del_num++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (del_num);
}

static void		ft_trim(char const *s1, char const *set, char *clone)
{
	size_t		i;
	size_t		j;
	size_t		del_num;

	i = 0;
	del_num = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				del_num++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			clone[i - del_num] = s1[i];
		i++;
	}
	clone[i] = 0;
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		del_num;
	char		*clone;

	del_num = ft_del_num(s1, set);
	if (!(clone = (char *)malloc(sizeof(char) * (ft_strlen(s1) - del_num + 1))))
		return (NULL);
	ft_trim(s1, set, clone);
	return (clone);
}
