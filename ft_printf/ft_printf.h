/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:58:45 by saoh              #+#    #+#             */
/*   Updated: 2020/11/04 14:14:42 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct			s_list
{
		void			*content;
		struct s_list	*next;
}						t_list;

typedef struct			s_lst
{
		va_list			*ap;
		const char		*f;
		char			*print;
		int				result;
}						t_lst;

int		ft_printf(char *f, ...);

#endif
