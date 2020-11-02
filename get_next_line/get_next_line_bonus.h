/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:12 by saoh              #+#    #+#             */
/*   Updated: 2020/11/02 13:52:18 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_substr(const char *str, unsigned int start, size_t len);

int			get_next_line(int fd, char **line);

#endif
