/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:58:45 by saoh              #+#    #+#             */
/*   Updated: 2020/11/08 20:42:31 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_lst
{
		va_list			*ap;
		const char		*f;
		char			*chrf;
		t_list			l_list;
		int				result;
		char			minus;
		char			nm;
		char			zero;
		char			precision;
		char			star;
}						t_lst;

int		ft_printf(const char *f);

#endif
