# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 10:49:10 by tbrandt           #+#    #+#              #
#    Updated: 2022/12/13 10:59:36 by tbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = cub3D
I_DIR = include
L_FT = libft
M_MLX = minilibx

SRC =	parsing/check_file.c	\
		parsing/utils.c			\
		parsing/ft_split.c		\
		parsing/read_file.c		\
		raycasting/set_params.c	\
		raycasting/colors.c		\
		raycasting/painting.c	\
		raycasting/dda.c		\
		main.c					\

OBJ = $(SRC:%.c=%.o)

all: cub.h $(NAME)

$(NAME): $(L_FT)/libft.a $(OBJ)
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_FT) -L$(M_MLX) -lft

$(L_FT)/libft.a:
	make -C $(L_FT)

%.o: %.c
	$(CC) -g -o $@ -c $< -I mlx

clean:
	make clean -C $(L_FT)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(L_FT)
	rm  -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
