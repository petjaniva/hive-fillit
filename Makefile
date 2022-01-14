# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:13:03 by pniva             #+#    #+#              #
#    Updated: 2022/01/14 13:55:58 by pniva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
		srcs/helper_functions.c \
		srcs/read.c \
		srcs/validate.c \
		srcs/solve.c \
		srcs/align.c \
		srcs/solve_helpers.c \
		srcs/find_place_for_mino.c

NAME = fillit

CC = clang

FLAGS = -g -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes -L ./libft -lft

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

libft:
		@make -C ./libft/ fclean && make -C ./libft/

test:
		@cd tests; \
		bash scripted_test.sh

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
