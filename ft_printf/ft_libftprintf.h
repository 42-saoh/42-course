/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:58:45 by saoh              #+#    #+#             */
/*   Updated: 2020/11/10 17:58:19 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct			s_lst
{
		va_list			*ap;
		const char		*f;
		char			*chrf;
		char			minus;
		char			nm;
		char			zero;
		char			precision;
		int				result;
		int				width;
		int				prewidth;
		int				len;
		t_list			list;
}						t_lst;

int						ft_printf(const char *f, ...);
t_lst					ft_sort_symbol(t_lst lst);
t_lst					ft_width(t_lst lst);
t_lst					ft_variable_argument_width(t_lst lst);
t_lst					ft_format_specifier(t_lst lst);

t_lst					ft_char(t_lst lst);
t_lst					ft_str(t_lst lst);

int						ft_strilen(const char *str);
t_lst					ft_width_select(t_lst lst);

#endif
