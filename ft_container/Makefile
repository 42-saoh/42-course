NAME	= ft_container
SNAME	= std_container
TNAME	= speed_test
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC 	= main.cpp

SRCDIR	= ./
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.cpp=.o)
INCDIR	= ./

$(NAME):
	c++ $(CXXFLAGS) -I$(INCDIR) $(SRCS) -o $(NAME)

test:
	c++ $(CXXFLAGS) -D stdtest=1 -I$(INCDIR) $(SRCS) -o $(SNAME)

test1:
	c++ $(CXXFLAGS) -I$(INCDIR) test.cpp -o $(TNAME)

all: $(NAME) test test1

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SNAME) $(TNAME)

re: fclean all
