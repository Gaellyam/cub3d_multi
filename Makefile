# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galamy <galamy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 09:25:39 by glamy             #+#    #+#              #
#    Updated: 2023/05/16 01:42:08 by galamy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRC_NAME = cub3d.c error.c get_next_line.c init.c key.c map.c move.c param.c parse_setup.c raycast.c run.c texture.c utils.c parse_map.c check_all_setup.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<


HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror -g #-fsanitize=address

LIBFT	= libft.a

LIBMLX	= libmlx.a

LIBS	= -L./libs/libft -lft -L./libs/mlx -lmlx -lXext -lX11 -lm

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc $(CFLAG) -o  $(NAME) $(OBJ) $(HEADER) $(LIBS)


$(LIBFT):
	$(MAKE) -C libs/libft

$(LIBMLX):
	$(MAKE) -C libs/mlx
	cp ./libs/mlx/$(LIBMLX) ./
 
clean	:
	$(MAKE) -C libs/libft clean
	$(MAKE) -C libs/mlx clean
	rm -rf ./$(LIBMLX) 
	rm -rf $(OBJ_PATH)

fclean	: clean
	$(MAKE) -C libs/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re