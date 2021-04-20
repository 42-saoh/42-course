#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include "libasm_bonus.h"

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *str1, const char *str2);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(const char *str);

#endif
