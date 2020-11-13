# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2020/11/13 14:29:18 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = test.o
LIBFT = -L./libft -lft

SRC := test.c

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
