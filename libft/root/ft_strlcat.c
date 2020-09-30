/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh </var/mail/saoh>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:10:01 by saoh              #+#    #+#             */
/*   Updated: 2020/09/30 20:49:04 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

static size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (dest_len + 1 < n)
	{
		while (i < n - 1)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	else
		return (src_len + n);
	return (dest_len + src_len);
}

int main()
{
	char dest[100];
	char src[100];
	
	printf("%lu %s\n", strlcat(dest, "power", 2), dest);
	printf("%lu %s\n", ft_strlcat(src, "power", 2), dest);
	strcpy(dest, "a");
	printf("system:\n");
	printf("%lu %s\n", strlcat(dest, "power", 2), dest);
	printf("%lu %s\n", strlcat(dest, "po", 100), dest);
	printf("%lu %s\n", strlcat(dest, "ma", 2), dest);
	printf("%lu %s\n", strlcat(dest, "naver", 20), dest);
	printf("%lu %s\n", strlcat(dest, "zero", 0), dest);
	printf("\n----------------\nUser Created:\n");
	strncpy(dest, "a", 70);
	printf("%lu %s\n", ft_strlcat(dest, "power", 2), dest);
	printf("%lu %s\n", ft_strlcat(dest, "po", 100), dest);
	printf("%lu %s\n", ft_strlcat(dest, "ma", 2), dest);
	printf("%lu %s\n", ft_strlcat(dest, "naver", 20), dest);
	printf("%lu %s\n", ft_strlcat(dest, "zero", 0), dest);
}
