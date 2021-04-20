NAME = libasm.a

SRCS = ft_strlen.s \
	   ft_strcpy.s \
	   ft_strcmp.s \
	   ft_write.s \
	   ft_read.s \
	   ft_strdup.s

BONUS = ft_atoi_base_bonus.s \
		ft_list_push_front_bonus.s \
		ft_list_size_bonus.s \
		ft_list_remove_if_bonus.s

OBJECT = $(SRCS:.s=.o)
BONUS_OBJECT = $(BONUS:.s=.o)

%.o	: %.s
		nasm -f macho64 $< -o $@

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

bonus : $(NAME) $(BONUS_OBJECT)
	ar rcs $(NAME) $(BONUS_OBJECT)

clean : 
	rm -r *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
