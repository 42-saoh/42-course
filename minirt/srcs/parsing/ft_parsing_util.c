/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:57:21 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:09:27 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*cut_space(char *line)
{
	if (line == NULL)
		return (NULL);
	while (*line == ' ')
		line++;
	return (line);
}

char			*is_comma(char *line)
{
	if (line == NULL)
		return (NULL);
	if (*line == ',')
		return (line + 1);
	else
		return (NULL);

}

char			*check_minus_and_numset(char *line, int *minus, double *result)
{
	if (*line == '-')
	{
		line++;
		*minus = -1;
	}
	else if (*line >= '0' && *line <= '9')
		*minus = 1;
	else
		return (NULL);
	*result = 0;
	return (line);
}

char			*get_double(char *line, double *num)
{
	double		result;
	double		ct;
	int			m;

	line = check_minus_and_numset(line, &m, &result);
	while (*line >= '0' && *line <= '9')
	{
		result = (result * 10) + (*line - '0');
		line++;
	}
	if (*line == '.')
	{
		line++;
		ct = 0;
		while (*line >= '0' && *line <= '9')
		{
			result = (result * 10) + (*line - '0');
			line++;
			ct++;
		}
		result /= pow(10.0, ct);
	}
	if (line != NULL)
		*num = result * m;
	return (line);
}

char			*get_num(char *line, int *num)
{
	int			result;

	if (!(*line >= '0' && *line <= '9'))
		return (NULL);
	result = 0;
	while (*line >= '0' && *line <= '9')
	{
		result = (result * 10) + (*line - '0');
		line++;
	}
	*num = result;
	return (line);
}
