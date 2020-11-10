# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2020/11/10 16:17:51 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = test.o
LIBFT = -L./libft -lft
INC_LINK = -I.ft_libftprintf.h

$(OBJECTS)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) $(INC_LINK) -o $@ -c $<

SRC := test.c

$(NAME) : $(OBJECTS) lib
	$(CC) $(CFLAGS) $(OBJECTS) $(INC_LINK) $(LIBFT) -o $(NAME)

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
