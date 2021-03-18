# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saoh </var/mail/saoh>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:14:14 by saoh              #+#    #+#              #
#    Updated: 2021/03/17 18:55:15 by saoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minirt
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC 	= main.c ch10.c ft_bmp.c ft_cal.c ft_color.c ft_img.c \
		  ft_mlx.c ft_random_double.c ft_thread.c ft_draw_hittable_material.c \
		  material/ft_material.c material/ft_simple_material.c material/ft_sphere.c material/ft_sphere_hit.c \
		  material/ft_plane.c material/ft_plane_hit.c material/ft_cylinder.c material/ft_cylinder_hit.c material/ft_cylinder_hit2.c \
		  material/ft_triangle.c material/ft_triangle_hit.c material/ft_square.c material/ft_square_hit.c \
		  struct/ft_camera.c struct/ft_hit_record.c struct/ft_hitlst.c struct/ft_hitlst_info.c \
		  struct/ft_hittable_util.c struct/ft_ray.c \
		  vec/ft_vec_apply.c vec/ft_vec_cal.c vec/ft_vec_create.c vec/ft_vec_extra.c \
		  vec/ft_vec_random.c vec/ft_vec_utils.c

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
	@$(MAKE) -C ./libft bonus
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
