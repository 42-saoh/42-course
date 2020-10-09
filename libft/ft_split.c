/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:13:06 by saoh              #+#    #+#             */
/*   Updated: 2020/10/09 11:23:29 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_len(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static size_t	ft_split_count(char const *s, char c)
{
	size_t		i;
	size_t		ct;

	i = 0;
	ct = 1;
	while (s[i] == c && s[i])
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			ct++;
		i++;
	}
	return (ct);
}

static int		ft_split_s(char const *s, char c, char **sp_s)
{
	size_t		i;
	size_t		j;
	size_t		ct;
	size_t		sp_len;

	i = 0;
	ct = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		sp_len = ft_split_len(s + i, c);
		if (!(sp_s[ct] = (char *)malloc(sizeof(char) * (sp_len + 1))))
			return (0);
		while (s[i] != c && s[i])
			sp_s[ct][j++] = s[i++];
		while (s[i] == c && s[i])
			i++;
		sp_s[ct++][j] = 0;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	size_t		sp_ct;
	char		**sp_s;

	sp_ct = ft_split_count(s, c);
	if (!(sp_s = (char **)malloc(sizeof(char *) * (sp_ct + 1))))
		return (NULL);
	if (ft_split_s(s, c, sp_s) == 0)
		return (NULL);
	sp_s[sp_ct] = 0;
	return (sp_s);
}
