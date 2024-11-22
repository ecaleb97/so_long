# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: envillan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 10:48:18 by envillan          #+#    #+#              #
#    Updated: 2024/11/22 10:48:20 by envillan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
MLX_DIR		=	minilibx-linux
LFT			=	libft/libft.a
INC			=	-I ./libft -I ./minilibx-linux
LIB			=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
SRC			=	src/render_game.c \
				src/handle_key.c \
				src/map_init.c \
				src/map_is_valid.c \
				src/map_parsing.c \
				src/utils.c \
				src/player_moves.c \
				src/root_destroy.c \
				src/root_init.c \
				src/so_long.c \
				src/flood_fill.c \
				src/update_game.c

OBJ			=	$(SRC:src/%.c=obj/%.o)

all:		$(MLX_DIR)/libmlx.a $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX_DIR)/libmlx.a:
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C $(MLX_DIR)
			@echo " [ OK ] | Minilibx ready!"

$(LFT):
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@make -s clean -C $(MLX_DIR)
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
