# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2020/11/26 19:33:18 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = *.o
LIBFT = -L./libft -lft

SRC := ft_adress.c \
	ft_char.c \
	ft_error_result.c \
	ft_flag_int_select.c \
	ft_flag_unsigned_select.c \
	ft_format_specifier.c \
	ft_int.c \
	ft_libftprintf.c \
	ft_lower_hexadecimal.c \
	ft_persent.c \
	ft_put_symbol.c \
	ft_sort_symbol.c \
	ft_str.c \
	ft_strilen.c \
	ft_unsigned.c \
	ft_upper_hexadecimal.c \
	ft_variable_argument_width.c \
	ft_width.c \

$(NAME) : lib
	@cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJECTS)

lib :
	@$(MAKE) -C ./libft bonus

all : $(NAME)

clean :
	@$(MAKE) -C ./libft clean
	$(RM) $(OBJECTS)

fclean : clean
	@$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re : fclean all
