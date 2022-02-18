NAME	= Zombie
CPPFLAGS	= -Wall -Wextra -Werror

SRC 	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

SRCDIR	= ./
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.cpp=.o)
INCDIR	= ./

%.o:	%.cpp
			c++ $(CPPFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) -I$(INCDIR) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
