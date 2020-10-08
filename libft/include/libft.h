#ifndef	LIBFT_H
#define	LIBFT_H

int		ft_atoi(const char *str);
void	ft_bzero(void *src, size_t size);
void	*ft_calloc(size_t elt_count, size_t elt_size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memccpy(void *dest, void *src, int c, size_t size);
void	*ft_memchr(void *ptr, int val, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void	*ft_memcpy(void *dest, void *src, size_t size);
void	*ft_memmove(void *dest, void *src, size_t size);
void	*ft_memset(void *dest, int val, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);;
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t c);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *str, unsigned int start, size_t len);
int		ft_tolower(int ch);
int		ft_toupper(int ch);

#endif
