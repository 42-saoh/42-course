# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2020/11/08 17:41:29 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ft_libftprintf.o
LIBFT = -L./libft -lft
INC_LINK = -I./libft/libft.h -I.ft_libftprintf.h

$(OBJECTS)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) $(INC_LINK) -o $@ -c $<

SRC := ft_libftprintf.c

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
