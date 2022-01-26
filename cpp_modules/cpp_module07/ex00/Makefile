NAME	= few_func
CPPFLAGS	= -Wall -Wextra -Werror

SRC 	= main.cpp

SRCDIR	= ./
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.cpp=.o)
INCDIR	= ./

%.o:	%.c
			c++ $(CPPFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) -I$(INCDIR) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
