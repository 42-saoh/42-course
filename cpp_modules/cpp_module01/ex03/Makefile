NAME	=  Unnecessary_violence
CPPFLAGS	= -Wall -Wextra -Werror

SRC 	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp 

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
