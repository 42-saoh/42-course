/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:13:06 by saoh              #+#    #+#             */
/*   Updated: 2020/10/04 17:47:15 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_split_count(char const *s, char c)
{
	size_t		i;
	size_t		sp_ct;

	i = 0;
	sp_ct = 1;
	if (s[0] == c)

	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			sp_ct++;
		i++;
	}
	return (sp_ct);
}

int				ft_split_s(char const *s, char c, char **sp_s)
{
	size_t		i;
	size_t		j;
	size_t		ct;
	size_t		cutline;
	size_t		sub_line;

	i = 0;
	ct = 0;
	sub_line = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
		{
			cutline = i;
			sp_s[ct] = (char *)malloc(sizeof(char) * (cutline - sub_line + 1))
			sub_line = cutline + 1;
			ct++;
		}
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	size_t		sp_ct;
	char		**sp_s;

	sp_ct = ft_split_count(s, c);
	if (!(sp_s = (char **)malloc(sizeof(char *) * sp_ct)))
		return (NULL);
	if (ft_split_s(s, c, sp_s) == 0)
		return (NULL);
}
