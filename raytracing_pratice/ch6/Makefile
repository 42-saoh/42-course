# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2021/01/05 16:59:27 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtest.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = *.o
LIBFT = -L./libft -lft

SRC := *.c

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
