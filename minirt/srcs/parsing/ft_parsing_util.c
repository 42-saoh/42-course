/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:57:21 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 18:40:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*is_comma(char *line, t_rt *rt)
{
	if (*line == ',')
		return (line + 1);
	else
	{
		rt->is_error = 1;
		return (line);
	}

}

char			*get_double2(char *line, double *num, double result, int m)
{
	int			ct;

	ct = 0;
	if (*line == '.' && (*(line + 1) >= '0' && *(line + 1) <= '9'))
	{
		line++;
		while (*line >= '0' && *line <= '9')
		{
			result = (result * 10) + (*line - '0');
			line++;
			ct++;
		}
		result /= pow(10.0, ct);
	}
	*num = result * m;
	return (line);
}

char			*get_double(char *line, double *num, t_rt *rt)
{
	double		result;
	int			m;

	if (*line == '-')
	{
		line++;
		m = -1;
	}
	else if (*line >= '0' && *line <= '9')
		m = 1;
	else
	{
		rt->is_error = 1;
		return (line);
	}
	result = 0;
	while (*line >= '0' && *line <= '9')
	{
		result = (result * 10) + (*line - '0');
		line++;
	}
	return (get_double2(line, num, result, m));
}

char			*get_num(char *line, int *num, t_rt *rt)
{
	int			result;

	if (*line == 0 || (*line < '0' && *line > '9'))
	{
		rt->is_error = 1;
		return (line);
	}
	result = 0;
	while (*line >= '0' && *line <= '9')
	{
		result = (result * 10) + (*line - '0');
		line++;
	}
	*num = result;
	return (line);
}
