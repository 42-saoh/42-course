/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:58:45 by saoh              #+#    #+#             */
/*   Updated: 2020/11/13 16:52:18 by saoh             ###   ########.fr       */
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
		char			minus;
		char			nm;
		char			zero;
		char			precision;
		int				result;
		int				width;
		int				prewidth;
		int				len;
		char			*chrf;
		char			*f;
		va_list			ap;
		t_list			*list;
}						t_lst;

int						ft_printf(const char *f, ...);
void					ft_sort_symbol(t_lst *lst);
void					ft_width(t_lst *lst);
void					ft_variable_argument_width(t_lst *lst);
void					ft_format_specifier(t_lst *lst);

void					ft_put_symbol(char *str, int start, int end, char c);

void					ft_char(t_lst *lst);
void					ft_str(t_lst *lst);
void					ft_adress(t_lst *lst);

int						ft_strilen(const char *str);
void					ft_width_select(t_lst *lst);

#endif
