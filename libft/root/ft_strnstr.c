/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:17:20 by saoh              #+#    #+#             */
/*   Updated: 2020/09/30 19:11:37 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>


char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	ct;
	size_t	str2_len;

	i = 0;
	while (str2[i])
		i++;
	str2_len = i;
	if (str2_len == 0)
		return ((char *)str1);
	i = 0;
	while (i < len)
	{
		ct = 0;
		while (count < str2_len)
		{
			if (str1[(i + ct)] != str2[(i + ct)])
				break;
			ct++;
			if (ct == str2_len)
				return ((char *)str1 + i);
		}
		i++;
	}
	return (NULL);
}

int main()
{
	char a[] = "abcde";
	char *c;
	char *b;

	c = strnstr(a, "cd", 5);
	printf("%c %s \n", *c, c);
	b = ft_strnstr(a, "cd", 5);
	printf("%c %s \n", *b, b);
}
