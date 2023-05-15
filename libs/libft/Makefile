# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galamy <galamy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:37:16 by galamy            #+#    #+#              #
#    Updated: 2022/11/17 16:52:49 by galamy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
SRCS =		ft_atoi.c		ft_bzero.c		ft_calloc.c	\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c 	ft_isdigit.c 	ft_isprint.c\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c\
			ft_strchr.c		ft_strdup.c		ft_strlcat.c	ft_strlcpy.c\
			ft_strlen.c		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c\
			ft_tolower.c	ft_toupper.c \
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c\
			ft_itoa.c		ft_strmapi.c	ft_striteri.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c \
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c 	ft_lstadd_back.c	ft_lstdelone.c \
			ft_lstclear.c 	ft_lstiter.c		ft_lstmap.c \
			get_next_line.c ft_strjoin_free.c	ft_atol.c ft_strcmp.c ft_putstr.c ft_putnbr.c
OBJS_FILES = $(SRCS:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES))
$(OBJS_PATH)/%.o: %.c 
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

$(NAME): $(OBJS) libft.h
		@ar rc $(NAME) $(OBJS) libft.h
		@echo "\033[32mCOMPILATION LIBFT OK\033[0m"

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $< 

clean: 
	@rm -rf $(OBJS_PATH)
	@echo "\033[32mCLEAN LIB OBJECT OK\033[0m"
fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mCLEAN LIB OK\033[0m"

re: fclean all

.PHONY : re clean fclean
