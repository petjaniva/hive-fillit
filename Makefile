# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:13:03 by pniva             #+#    #+#              #
#    Updated: 2022/01/13 10:25:04 by pniva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
		srcs/helper_functions.c \
		srcs/read.c \
		srcs/validate.c \
		srcs/solve.c \
		srcs/align.c \
		srcs/solve_helpers.c

NAME = fillit

CC = gcc

FLAGS = -g -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes -L ./libft -lft

all: $(NAME)

$(NAME):
		@make -C ./libft/ fclean && make -C ./libft/
		$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
