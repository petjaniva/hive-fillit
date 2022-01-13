# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:13:03 by pniva             #+#    #+#              #
#    Updated: 2022/01/13 13:26:06 by bkandemi         ###   ########.fr        #
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

CC_LEAK = /usr/local/opt/llvm/bin/clang -fsanitize=leak

FLAGS = -g -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes -L ./libft -lft

all: $(NAME)

$(NAME):
		@make -C ./libft/ fclean && make -C ./libft/
		$(CC_LEAK) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
