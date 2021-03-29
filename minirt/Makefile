# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2021/03/26 12:46:13 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minirt
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC 	= main.c ft_bmp.c ft_cal.c ft_color.c ft_img.c ft_light.c ft_ambient.c \
		  ft_mlx.c ft_random_double.c ft_thread.c ft_draw.c ft_error.c \
		  material/ft_sphere.c material/ft_sphere_hit.c material/ft_plane.c material/ft_plane_hit.c \
		  material/ft_cylinder.c material/ft_cylinder_hit.c material/ft_cylinder_hit2.c \
		  material/ft_triangle.c material/ft_triangle_hit.c material/ft_square.c material/ft_square_hit.c \
		  material/ft_sphere_s_hit.c material/ft_plane_s_hit.c material/ft_cylinder_s_hit.c \
		  material/ft_triangle_s_hit.c material/ft_square_s_hit.c \
		  struct/ft_camera.c struct/ft_hit_record.c struct/ft_hitlst.c struct/ft_hitlst_info.c \
		  struct/ft_hittable_util.c struct/ft_ray.c \
		  vec/ft_vec_apply.c vec/ft_vec_cal.c vec/ft_vec_create.c vec/ft_vec_extra.c \
		  vec/ft_vec_random.c vec/ft_vec_utils.c \
		  parsing/ft_check_rt.c parsing/ft_parsing_ambient.c parsing/ft_parsing_camera.c \
		  parsing/ft_parsing_cylinder.c parsing/ft_parsing_img.c parsing/ft_parsing_light.c \
		  parsing/ft_parsing_main.c parsing/ft_parsing_plane.c parsing/ft_parsing_sphere.c \
		  parsing/ft_parsing_square.c parsing/ft_parsing_triangle.c \
		  parsing/ft_parsing_util.c parsing/ft_parsing_util2.c \

SRCDIR	= ./srcs/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)
LIBNAME	= libft.a
MLXNAME = libmlx.dylib
INCDIR	= ./includes/

%.o:	%.c
			$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(LIBNAME) $(MLXNAME) $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) -L. -lmlx -o $(NAME) $(OBJS) $(LIBNAME) $(MLXNAME)

$(LIBNAME):
	@$(MAKE) -C ./libft gnl
	@cp libft/$(LIBNAME) $(LIBNAME)

$(MLXNAME):
	@$(MAKE) -C ./mlx
	@cp mlx/$(MLXNAME) $(MLXNAME)

all: $(NAME)

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./mlx clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C ./libft fclean
	$(RM) $(LIBNAME) $(MLXNAME) $(NAME)

re: fclean all
