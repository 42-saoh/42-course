# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 13:14:14 by saoh              #+#    #+#              #
#    Updated: 2021/09/26 17:20:16 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC 	= main.c error.c path.c utils.c start_pipe.c

SRCDIR	= ./
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)
INCDIR	= ./

%.o:	%.c
			$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
