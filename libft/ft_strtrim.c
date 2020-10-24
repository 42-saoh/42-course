/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:18:36 by saoh              #+#    #+#             */
/*   Updated: 2020/10/24 16:09:02 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_front_del_num(char const *s1, char const *set)
{
	int			i;
	size_t		j;
	size_t		flag;
	size_t		del_num;

	i = -1;
	del_num = 0;
	while (s1[++i])
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				flag++;
				del_num++;
				break ;
			}
			j++;
		}
		if (flag == 0)
			break ;
	}
	return (del_num);
}

static size_t	ft_back_del_num(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		flag;
	size_t		del_num;

	i = ft_strlen(s1);
	del_num = 0;
	while (--i >= 0)
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				flag++;
				del_num++;
				break ;
			}
			j++;
		}
		if (flag == 0)
			break ;
	}
	return (del_num);
}

static char		*ft_trim(char const *s1, size_t fdn, size_t bdn)
{
	size_t		i;
	size_t		del_num;
	char		*trim;

	i = 0;
	del_num = fdn + bdn;
	if (!(trim = (char *)malloc(sizeof(char) * (ft_strlen(s1) - del_num + 1))))
		return (NULL);
	del_num = 0;
	while (s1[i])
	{
		if (i < fdn)
		{
			i++;
			del_num++;
			continue ;
		}
		else if (i == ft_strlen(s1) - bdn)
			break ;
		trim[i - del_num] = s1[i];
		i++;
	}
	trim[i - del_num] = 0;
	return (trim);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		front_del_num;
	size_t		back_del_num;
	char		*trim;

	if (s1 == NULL)
	{
		trim = 0;
		return (trim);
	}
	if (set == NULL)
		return (ft_strdup(s1));
	front_del_num = ft_front_del_num(s1, set);
	if (front_del_num == ft_strlen(s1))
		return (ft_strdup(""));
	back_del_num = ft_back_del_num(s1, set);
	if ((trim = ft_trim(s1, front_del_num, back_del_num)) == NULL)
		return (NULL);
	return (trim);
}
